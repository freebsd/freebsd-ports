# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	s5
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://meyerweb.com/eric/tools/s5/v/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple HTML-based presentation system

LICENSE=	BSD2CLAUSE PD
LICENSE_COMB=	multi

USES=		dos2unix zip
DOS2UNIX_REGEX=	.*\.(css|htc|html|js|txt)

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	s5 s5.1

S5_DIR=		${PREFIX}/share/${PORTNAME}
S5_SUBDIRS=	pix primer s5-blank ui

post-extract:
	@cd ${WRKSRC} && ${TAR} -xf s5-blank.zip
	@${FIND} ${WRKSRC} -type f -name .DS_Store -delete

do-install:
	@${MKDIR} ${STAGEDIR}${S5_DIR}
	@(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "*.html ${S5_SUBDIRS}" ${STAGEDIR}${S5_DIR})
	${INSTALL_SCRIPT} ${WRKDIR}/s5 ${STAGEDIR}${PREFIX}/bin/s5
	${INSTALL_MAN} ${WRKDIR}/s5.1 ${STAGEDIR}${MANPREFIX}/man/man1/s5.1

.include <bsd.port.mk>
