# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	archiveopteryx
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	GH

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Advanced PostgreSQL-based IMAP/POP server

LICENSE=	MIT

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam

USES=	perl5
USE_PERL5=	build
USE_PGSQL=	yes
WANT_PGSQL_VER=	91+

USE_GITHUB=	yes
GH_ACCOUNT=	aox
GH_PROJECT=	aox
GH_TAGNAME=	v3.2.0
GH_COMMIT=	2a5d127e

WRKSRC=	${WRKDIR}/aox-aox-a55036e

PORTDOCS=	COPYING README bsd.txt

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

USERS=		aox
GROUPS=		aox
PLIST_SUB+=	USERS="${USERS}"
PLIST_SUB+=	GROUPS="${GROUPS}"

JAM?=		${LOCALBASE}/bin/jam

.include <bsd.port.pre.mk>

# force Clang when on FreeBSD 10+
.if ${OSVERSION} >= 1000000
JAMARG=	"-sCLANG=1"
.endif

post-patch:
	@${GREP} -Rl '%%[[:alpha:]]\+%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e 's,%%PREFIX%%,${PREFIX},g'
	${REINPLACE_CMD} "s|INSTALLROOT ?= \"\" ;|INSTALLROOT = \"${STAGEDIR}\" ;|" ${WRKSRC}/Jamsettings

do-build:
	@cd ${WRKSRC} && ${JAM} ${JAMARG}

do-install:
	@cd ${WRKSRC} && ${JAM} ${JAMARG} install

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
