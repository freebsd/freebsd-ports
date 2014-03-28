# $FreeBSD$

PORTNAME=	poudriere
PORTVERSION=	3.0.99.20140320
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://fossil.etoilebsd.net/poudriere/tarball/ \
		LOCAL/bdrewery/${PORTNAME}/
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz?uuid=${FSL_CHKIN}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD2CLAUSE

CONFLICTS_INSTALL=	poudriere-[0-9]*

FSL_CHKIN=	0966e62bc4

USES=		uidfix
GNU_CONFIGURE=	yes
ETCDIR=		${PREFIX}/etc/poudriere.d

OPTIONS_DEFINE=	ZSH
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MZSH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_poudriere \
	    ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
.endif

.include <bsd.port.mk>
