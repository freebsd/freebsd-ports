# New ports collection makefile for:	newsx
# Date created: 10th February, 2001
# Whom:		Thierry Thomas <tthomas@mail.dotcom.fr>
#
# $FreeBSD$
#

PORTNAME=	newsx
PORTVERSION=	1.4.6
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.kvaleberg.com/pub/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.6/pl6/}

MAINTAINER=	thierry@pompo.net

.if defined(WITH_CNEWS)
BUILD_DEPENDS=	${LOCALBASE}/news/lib/libcnews.a:${PORTSDIR}/news/cnews
.else !defined(WITHOUT_INN_2-X)
BUILD_DEPENDS=	${LOCALBASE}/news/lib/libinn.a:${PORTSDIR}/news/inn
.endif

USE_AUTOMAKE_VER=14
CONFIGURE_ENV=	PATH="${PATH}:${LOCALBASE}/news/bin"
.if !defined(WITH_CNEWS)
.if !defined(WITHOUT_INN_2-X)
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/news/include"
CONFIGURE_ARGS=	--with-newslib=${LOCALBASE}/news/lib
.endif
.endif

HDR_DIR=	${LOCALBASE}/news/include

DOCS=		AUTHORS COPYING ChangeLog FAQ INSTALL NEWS README TODO

post-patch:
	@${PERL} -pi -e "s:%%LOCALBASE%%:${LOCALBASE}:" ${WRKSRC}/configure.in

pre-configure:
	@${ECHO} "*********************************************************"
	@${ECHO} "If the configure step fails, then you probably don't have"
	@${ECHO} "a news server package installed.  Try installing INN from"
	@${ECHO} "${PORTSDIR}/news/inn, and then try building this port"
	@${ECHO} "again."
	@${ECHO} "*********************************************************"

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
