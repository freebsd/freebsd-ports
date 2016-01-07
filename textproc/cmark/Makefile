# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	cmark
PORTVERSION=	0.23.0
CATEGORIES=	textproc

MAINTAINER=	t@tobik.me
COMMENT=	CommonMark parsing and rendering library and program in C

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	jgm

USES=		cmake:outsource
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -i "" 's|share/||g' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.mk>
