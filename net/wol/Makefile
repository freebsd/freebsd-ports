# ex:ts=8
# Ports collection makefile for:	wol
# Date created:			Jan 10, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	wol
PORTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ahh

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Tool to wake up Wake-On-LAN compliant computers

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		iconv.3:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=		yes
USE_GETOPT_LONG=	yes
CPPFLAGS=		-I${LOCALBASE}/include
LDFLAGS=		-L${LOCALBASE}/lib
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

INFO=		wol
DOCS=		AUTHORS NEWS README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
