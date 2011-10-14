# New ports collection Makefile for:	gorilla
# Date created:				2006-02-11
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	gorilla
PORTVERSION=	1.5.3.4
DISTVERSIONSUFFIX=	7c3e819
CATEGORIES=	security
MASTER_SITES=	LOCAL/crees/gorilla				\
		http://www.bayofrum.net/dist/${PORTNAME}/
DISTNAME=	zdia-${PORTNAME}-v${DISTVERSION}-0-g${DISTVERSIONSUFFIX}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Password Gorilla is a cross-platform Password Manager

RUN_DEPENDS=	itcl>=3.4:${PORTSDIR}/lang/itcl \
		wish:${PORTSDIR}/x11-toolkits/tk-wrapper

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/zdia-${PORTNAME}-${DISTVERSIONSUFFIX}
USE_TCL_RUN=	85+
USE_TK=		85+
NO_BUILD=	yes
SUB_FILES=	gorilla
SUB_LIST=	WISH=${WISH}
PORTDOCS=	*

SRC_DIRS=	blowfish msgs pics pwsafe sha1 sha256c tooltip twofish

post-patch:
# We don't want Linux/Windows/Darwin binaries thank you
	${FIND} ${WRKSRC} \( \
		-name "*.so" \
		-or -name "*.dll" \
		-or -name "*.dylib" \
	   \) -delete

do-install:
	@${MKDIR} ${PREFIX}/lib/gorilla
	@${INSTALL_SCRIPT} ${WRKSRC}/sources/*.tcl ${PREFIX}/lib/gorilla
.for dir in ${SRC_DIRS}
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/${dir}
	@cd ${WRKSRC}/sources/${dir} \
		&& ${COPYTREE_SHARE} \* \
		${PREFIX}/lib/${PORTNAME}/${dir}
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

post-install:
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/gorilla
	@${FIND} ${PREFIX}/lib/${PORTNAME}/ -name "*.tcl" \
		| ${XARGS} ${CHMOD} ${BINMODE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README			\
		${WRKSRC}/sources/README.install-from-source	\
		${WRKSRC}/sources/CHANGES.txt			\
	   ${DOCSDIR}
.endif

.include <bsd.port.mk>
