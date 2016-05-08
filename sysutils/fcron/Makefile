# $FreeBSD$

PORTNAME=	fcron
PORTVERSION=	3.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://fcron.free.fr/archives/ \
		ftp://ftp.seul.org/pub/fcron/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	bob@eager.cx
COMMENT=	Periodic command scheduler

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS EXAMPLES

GNU_CONFIGURE=	yes
USES=		perl5 gmake
USE_PERL5=	build
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-cflags="${CFLAGS}" \
		--with-rootname=root --with-rootgroup=wheel \
		--with-docdir=${DOCSDIR} \
		--with-dsssl-dir=no

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USERS=		fcron
GROUPS=		fcron

USE_RC_SUBR=	fcron

SUB_FILES=	pkg-message

PAMDIR?=	etc/pam.d
PLIST_SUB+=	PAMDIR=etc/pam.d

PORTDOCS=	*

DOCSRC=		${WRKSRC}/doc/en

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fcron ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/fcrontab ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fcrondyn ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fcronsighup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/files/fcron.pam ${STAGEDIR}${PREFIX}/${PAMDIR}/fcron
	${INSTALL_DATA} ${WRKSRC}/files/fcrontab.pam ${STAGEDIR}${PREFIX}/${PAMDIR}/fcrontab
.for f in fcron.allow fcron.conf fcron.deny
	${INSTALL_DATA} -m 640 ${WRKSRC}/files/${f} ${STAGEDIR}${PREFIX}/etc/${f}.sample
.endfor
.for n in 1 5 8
	${INSTALL_MAN} ${DOCSRC}/man/*.${n} ${STAGEDIR}${PREFIX}/man/man${n}
.endfor

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/fcrontab-* ${WRKSRC}/files/*.pam ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
.for d in txt HTML
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${d}
	${INSTALL_DATA} ${DOCSRC}/${d}/* ${STAGEDIR}${DOCSDIR}/${d}
.endfor

post-install:
	${MKDIR} -m 770 ${STAGEDIR}/var/spool/fcron

.include <bsd.port.mk>
