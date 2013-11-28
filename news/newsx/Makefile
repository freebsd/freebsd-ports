# Created by: Thierry Thomas <tthomas@mail.dotcom.fr>
# $FreeBSD$

PORTNAME=	newsx
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	news
MASTER_SITES=	http://www.kvaleberg.org/pub/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A program to fetch news from and post news to a remote NNTP server

LICENSE=	GPLv2

.if defined(WITH_CNEWS)
BUILD_DEPENDS=	${LOCALBASE}/news/lib/libcnews.a:${PORTSDIR}/news/cnews
.elif !defined(WITHOUT_INN_2-X)
BUILD_DEPENDS=	${LOCALBASE}/news/lib/libinn.a:${PORTSDIR}/news/inn
.endif

GNU_CONFIGURE=	yes

CONFLICTS=	leafnode-1.*

.if !defined(WITH_CNEWS)
.if !defined(WITHOUT_INN_2-X)
CPPFLAGS+=	-I${LOCALBASE}/news/include
.endif
.endif

.if defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--without-history
.endif

DOCS=		AUTHORS COPYING ChangeLog FAQ INSTALL NEWS README TODO

pre-configure:
	${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:g" ${WRKSRC}/configure
	@${ECHO} "*********************************************************"
	@${ECHO} "If the configure step fails, then you probably don't have"
	@${ECHO} "a news server package installed.  Try installing INN from"
	@${ECHO} "${PORTSDIR}/news/inn, and then try building this port"
	@${ECHO} "again."
	@${ECHO} "*********************************************************"

post-build:
.if !defined(WITH_DEBUG)
	${STRIP_CMD} ${WRKSRC}/src/newsx
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/news/spool/inhosts
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	@${ECHO} "Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
