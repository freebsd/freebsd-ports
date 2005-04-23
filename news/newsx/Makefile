# New ports collection makefile for:	newsx
# Date created: 10th February, 2001
# Whom:		Thierry Thomas <tthomas@mail.dotcom.fr>
#
# $FreeBSD$
#

PORTNAME=	newsx
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.kvaleberg.com/pub/

MAINTAINER=	thierry@pompo.net
COMMENT=	A program to fetch news from and post news to a remote NNTP server

.if defined(WITH_CNEWS)
BUILD_DEPENDS=	${LOCALBASE}/news/lib/libcnews.a:${PORTSDIR}/news/cnews
.elif !defined(WITHOUT_INN_2-X)
BUILD_DEPENDS=	${LOCALBASE}/news/lib/libinn.a:${PORTSDIR}/news/inn
.endif

CONFLICTS=	leafnode-1.9.*

USE_REINPLACE=	yes
.if !defined(WITH_CNEWS)
.if !defined(WITHOUT_INN_2-X)
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/news/include"
.endif
.endif

DOCS=		AUTHORS COPYING ChangeLog FAQ INSTALL NEWS README TODO

post-patch:
	@${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:g" ${WRKSRC}/configure

pre-configure:
	@${ECHO} "*********************************************************"
	@${ECHO} "If the configure step fails, then you probably don't have"
	@${ECHO} "a news server package installed.  Try installing INN from"
	@${ECHO} "${PORTSDIR}/news/inn, and then try building this port"
	@${ECHO} "again."
	@${ECHO} "*********************************************************"

pre-install:
	@${STRIP_CMD} ${WRKSRC}/src/newsx

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO} "Documentation installed in ${DOCSDIR}."
.endif

MAN1=	newsq.1
MAN5=	newsx.conf.5 in.hosts.5
MAN8=	newsx.8

.include <bsd.port.mk>
