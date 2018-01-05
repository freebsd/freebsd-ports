# $FreeBSD$

PORTNAME=	ifmail
PORTVERSION=	2.15
PORTREVISION=	9
CATEGORIES=	news comms
MASTER_SITES=	SUNSITE/system/fido

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	FidoNet(tm) support package for UN*X platform

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/README

USES=		shebangfix
USERS=		ifmail
CFLAGS+=	-DHAS_STDARG_H -Wall
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" OWNER=${UID} GROUP=$$(id -g)

LMAN3=		parsedate.3
LMAN8=		ifmail.8 iftoss.8
SHEBANG_FILES=	misc/contrib/a2dbm \
		misc/contrib/abbs2nf/abbs2nf.pl \
		misc/contrib/areafix-0.5.07/areafix.pl \
		misc/contrib/areafix-0.5.07-jv10/areafix.pl \
		misc/contrib/areafix-0.6.02/areafix \
		misc/contrib/edalias \
		misc/contrib/edalias.cgi \
		misc/contrib/ifinfo \
		misc/contrib/ifinfo.pl \
		misc/contrib/ifman \
		misc/contrib/ifreq \
		misc/contrib/ldbm \
		misc/contrib/lmsgid \
		misc/contrib/sumlog \
		misc/contrib/tic/checker.pl \
		misc/contrib/tic/lister.pl \
		misc/contrib/tic/makeconfig.pl \
		misc/contrib/tic/poster.pl \
		misc/contrib/tic/process_tics.pl \
		misc/contrib/tic/purge_history.pl \
		misc/contrib/u-tic/make_machdep.pl \
		misc/contrib/u-tic/u-attach.pl \
		misc/contrib/u-tic/u-fix.pl \
		misc/contrib/u-tic/u-tic.pl

OPTIONS_DEFINE=	DOCS EXAMPLES

do-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/CONFIG

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/ifmail

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/ifmail/*
.for i in ${LMAN8}
	${INSTALL_MAN} ${WRKSRC}/ifgate/${i} ${STAGEDIR}${PREFIX}/man/man8/
.endfor
.for i in ${LMAN3}
	${INSTALL_MAN} ${WRKSRC}/iflib/${i} ${STAGEDIR}${PREFIX}/man/man3/
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.for i in ifcico ifgate iflib
	${INSTALL_DATA} ${WRKSRC}/${i}/README ${STAGEDIR}${DOCSDIR}/README.${i}
.endfor

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/misc -cf - . | ${TAR} -C ${STAGEDIR}${EXAMPLESDIR} -xf -

.include <bsd.port.mk>
