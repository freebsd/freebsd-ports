# ex:ts=8
# Ports collection makefile for:	GNUnet
# Date created:			Mar 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnunet
PORTVERSION=	0.3.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://gecko.cs.purdue.edu/gnunet/
MASTER_SITE_SUBDIR=	gnunet
DISTNAME=	GNUnet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	automake14:${PORTSDIR}/devel/automake14 \
		autoconf213:${PORTSDIR}/devel/autoconf213

USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_GTK=	yes
USE_GMAKE=	yes

do-configure:
	@(cd ${WRKSRC} ; \
	  ${ACLOCAL} ; \
	  ${AUTOCONF} ; \
	  ${AUTOHEADER} ; \
	  ${AUTOMAKE} -a ; \
	  ${CONFIGURE_SCRIPT})

.include <bsd.port.mk>
