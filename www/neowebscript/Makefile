# New ports collection makefile for:	neowebscript
# Date created:				October 28, 2001
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	neowebscript
PORTVERSION=	3.3
PORTREVISION=	3
CATEGORIES=	www tcl
MASTER_SITES=	SF/nws/nws/${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Embeds a TCL8 interpreter in the Apache server

LIB_DEPENDS=	neo82:${PORTSDIR}/devel/tcl-neo

USE_APACHE=	1.3
USE_TCL=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd
WRKSRC=		${WRKDIR}/${DISTNAME}/modules
MAKE_ENV+=	FILESDIR="${FILESDIR}" \
			INSTALL_DATA="${INSTALL_DATA}" \
			TCL_VERSION=${TCL_VER}
REINPLACE_ARGS=	-i ""
SUB_FILES+=	pkg-message neowebscript.conf

SUBDIRS=	modules neowebscript htdocs # tools

# Only extract what we care for -- the tarball also includes antiquated
# versions of Apache, TCL, TclX, ITCL, gd...
EXTRACT_AFTER_ARGS:=| ${TAR} -xf - ${SUBDIRS:%=${PORTNAME}-${PORTVERSION}/%}

post-patch:
	# Replacing writeGIF with writePNG
	${REINPLACE_CMD} 's/writeGIF/writePNG/g' \
		`${FIND} ${WRKSRC}/.. -type f | \
		${XARGS} ${GREP} -F -l --mmap writeGIF`

pre-install:
	# Removing *.orig files and empty directories:
	${FIND} ${WRKSRC}/../neowebscript ${WRKSRC}/../htdocs \
		\( -type f -name \*.orig -o -type d -empty \) -delete

post-install:
	@${CP} ${WRKSRC}/../../neowebscript.conf ${LOCALBASE}/${APACHEETCDIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@${CP} -Rp ${WRKSRC}/../htdocs/* ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
