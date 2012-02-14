# New ports collection makefile for:	ccze
# Date Created:				2nd june 2003
# Whom:					Nicolas Jombart <ecu@ipv42.net>
#
# $FreeBSD$
# ex:ts=8

PORTNAME=	ccze
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://falafel.200ok.org/distfiles/ccze/ \
		http://200ok.org/distfiles/ccze/

MAINTAINER=	ecu@ipv42.net
COMMENT=	Fast log colorizer

LIB_DEPENDS=	pcre.1:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		ccze.1 ccze-cssdump.1
MAN7=		ccze-plugin.7

post-install:
	@${WRKSRC}/src/ccze-dump > ${PREFIX}/etc/cczerc-sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
.endif

.include <bsd.port.mk>
