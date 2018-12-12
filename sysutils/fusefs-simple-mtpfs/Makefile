# $FreeBSD$

PORTNAME=	simple-mtpfs
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.3.0
PORTREVISION=	4
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple MTP fuse filesystem driver

LICENSE=	GPLv2+

LIB_DEPENDS=	libmtp.so:multimedia/libmtp

USE_GITHUB=	yes
GH_ACCOUNT=	phatina

USES=		autoreconf compiler:c++11-lib fuse localbase pkgconfig
GNU_CONFIGURE=	yes
MAKEFILE=	makefile
INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	AUTHORS NEWS README.md

OPTIONS_DEFINE=	DOCS

# XXX move to PREFIX when bug 193596 lands
.if exists(/etc/autofs)
PLIST_FILES+=	/etc/autofs/special_${PORTNAME}
SUB_FILES+=	special_${PORTNAME}
.endif

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})
.if exists(/etc/autofs)
	@${MKDIR} ${STAGEDIR}/etc/autofs
	${INSTALL_SCRIPT} ${WRKDIR}/special_${PORTNAME} \
		${STAGEDIR}/etc/autofs
.endif

.include <bsd.port.mk>
