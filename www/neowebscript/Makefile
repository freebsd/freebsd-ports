# New ports collection makefile for:	neowebscript
# Date created:				October 28, 2001
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	neowebscript
PORTVERSION=	3.3
CATEGORIES=	www tcl83
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=nws

MAINTAINER=	mi@aldan.algebra.com

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
LIB_DEPENDS=	neo82:${PORTSDIR}/devel/tcl-neo

MAKEFILE=	${FILESDIR}/Makefile.bsd
WRKSRC=		${WRKDIR}/${DISTNAME}/modules
MAKE_ENV+=	FILESDIR="${FILESDIR}" INSTALL_DATA="${INSTALL_DATA}"

SUBDIRS=	modules neowebscript htdocs # tools

# Only extract what we care for -- the tarball also includes antiquated
# versions of Apache, TCL, TclX, ITCL, gd...
EXTRACT_AFTER_ARGS:=| ${TAR} -xf - ${SUBDIRS:%=${PORTNAME}-${PORTVERSION}/%}

post-patch:
	# Replacing writeGIF with writePNG
	${PERL} -pi -e 's/writeGIF/writePNG/g' \
		`find ${WRKSRC}/.. -type f | xargs fgrep -l --mmap writeGIF`

pre-install:
	# Removing *.orig files and empty directories:
	find ${WRKSRC}/../neowebscript ${WRKSRC}/../htdocs \
		\( -type f -name \*.orig -o -type d -empty \) -delete

CONFSCRIPT=	${LOCALBASE}/etc/apache/neowebscript.conf
PREFIX_CMD=	's^/usr/local^${PREFIX}^g'

post-install:
	test -e ${CONFSCRIPT} || ${SED} ${PREFIX_CMD} < \
		${FILESDIR}/neowebscript.conf > ${CONFSCRIPT}
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -Rp ${WRKSRC}/../htdocs/* ${DOCSDIR}
.endif
	@${SED} ${PREFIX_CMD} < ${PKGMESSAGE}

.include <bsd.port.mk>
