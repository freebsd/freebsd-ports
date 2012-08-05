# New ports collection makefile for:	pks
# Date created:		15 Jan 2001
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		pks
PORTVERSION=		0.9.6.20040312
CATEGORIES=		security www
MASTER_SITES=		http://pks.sourceforge.net/:sf ${MASTER_SITE_LOCAL}:local
MASTER_SITE_SUBDIR=	.:sf mandree:local
DISTFILES=		pks-current.tgz:sf,local

MAINTAINER=	gtodd@bellanet.org
COMMENT=	PGP Public Key Server

USE_BDB=		41 # 42 would be ok
WRKSRC=			${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/pks --localstatedir=/var/pks \
		--sysconfdir=${EXAMPLESDIR} \
		--libdir=${LOCALBASE}/lib --with-libwrap
MAKE_ENV+=	SUBDIRS=
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	DBLIB="-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}" DBINC=-I${BDB_INCLUDE_DIR} DBHDR=db.h

USE_RC_SUBR=	pksd
MAN5=		pksd.conf.5
MAN8=		pks-intro.8 pksclient.8 pksd.8 pksdctl.8 pks-mail.sh.8 \
		pks-queue-run.sh.8 pgpsplit.8

SUB_FILES=	pkg-message pkg-deinstall

post-install:
	${INSTALL_DATA} ${WRKSRC}/pksd.conf ${PREFIX}/etc/pksd.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pks_help.en ${WRKSRC}/pks_help.es ${WRKSRC}/pks_help.fr \
	${WRKSRC}/pks_help.cz ${WRKSRC}/pks_help.de ${WRKSRC}/pks_help.ja \
	${WRKSRC}/mail_intro ${DOCSDIR}
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
