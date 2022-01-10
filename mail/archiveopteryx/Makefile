# Created by: Ashish SHUKLA <ashish@FreeBSD.org>

PORTNAME=	archiveopteryx
PORTVERSION=	3.2.0
PORTREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	http://archiveopteryx.org/download/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Advanced PostgreSQL-based IMAP/POP server

LICENSE=	MIT

BUILD_DEPENDS=	jam:devel/jam

USES=		compiler perl5 ssl tar:bzip2
USE_PERL5=	build
WITH_PGSQL=	client

CONFLICTS_INSTALL=	archiveopteryx-devel # bin/aox bin/aoxdeliver bin/aoxexport bin/aoximport

PORTDOCS=	COPYING README bsd.txt

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

USERS=		aox
GROUPS=		aox
PLIST_SUB+=	USERS="${USERS}"
PLIST_SUB+=	GROUPS="${GROUPS}"

JAM?=		${LOCALBASE}/bin/jam
JAMARG+=	-dx

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# force Clang when on FreeBSD with clang in base
.if ${OPSYS} == FreeBSD
.if ${CHOSEN_COMPILER_TYPE} == clang
JAMARG+=	"-sCLANG=1"
.endif
.endif

post-patch:
	@${EGREP} -Rl '%%[[:alpha:]]+%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e 's,%%PREFIX%%,${PREFIX},g'
	${REINPLACE_CMD} -e "s|\(C++FLAGS =\)|\1 -I${OPENSSLINC}|g" \
		-e"s|INSTALLROOT ?= \"\" ;|INSTALLROOT = \"${STAGEDIR}\" ;|" \
		${WRKSRC}/Jamsettings
	${REINPLACE_CMD} -e "s|\(-lcrypto\)|-L${OPENSSLLIB} \1|g" \
		${WRKSRC}/server/Jamfile

do-build:
	@cd ${WRKSRC} && ${JAM} ${JAMARG}

do-install:
	@cd ${WRKSRC} && ${JAM} ${JAMARG} install

.include <bsd.port.post.mk>
