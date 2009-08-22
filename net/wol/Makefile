# ex:ts=8
# Ports collection makefile for:	wol
# Date created:			Jan 10, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	wol
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/ahh/OldFiles

MAINTAINER=	cm@therek.net
COMMENT=	Tool to wake up Wake-On-LAN compliant computers

GNU_CONFIGURE=		yes
USE_PERL5_BUILD=	yes
CPPFLAGS=		-I${LOCALBASE}/include
LDFLAGS=		-L${LOCALBASE}/lib
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
USE_GETTEXT=	yes
USE_ICONV=	yes
PLIST_SUB=	NLS=""
.endif

MAN1=		wol.1
INFO=		wol
DOCS=		AUTHORS NEWS README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
