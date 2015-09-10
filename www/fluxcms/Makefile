# $FreeBSD$

PORTNAME=	fluxcms
PORTVERSION=	1.6.0
PORTREVISION=	8
CATEGORIES=	www
MASTER_SITES=	http://bitflux.org/download/ \
		http://www.chruetertee.ch/files/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-snapshot-20090308

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Extensible and flexible CMS based on PHP 5 and XML/XSLT

USES=		shebangfix tar:tgz
SHEBANG_FILES=	div/db/dbexport.sh \
		div/db/dbexport40.sh \
		inc/bx/tools/svnsync \
		webinc/bxe/firefox_extension/build.sh \
		webinc/bxe/util/js2doxy.pl
perl_OLD_CMD=	//usr/local/bin/perl
NO_BUILD=	yes
NO_ARCH=	yes
FLUXCMSDIR=	www/fluxcms
INSTALLDIR=	${PREFIX}/${FLUXCMSDIR}

PLIST_SUB=	INSTALLDIR=${FLUXCMSDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST=	INSTALLDIR=${INSTALLDIR}

OPTIONS_DEFINE=	TIDY

USE_PHP=	dom xml simplexml iconv mysql xsl session pcre gd

DEFAULT_PHP_VER=	5

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTIDY}
USE_PHP+=	tidy
.endif

post-patch:
	@${RM}  ${WRKSRC}/install/dist/conf/config.xml.orig

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALLDIR}
	@${CP} -R ${WRKSRC}/*  ${STAGEDIR}${INSTALLDIR}

.include <bsd.port.post.mk>
