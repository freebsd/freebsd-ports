# ex:ts=8
# Ports collection makefile for:  dict
# Date created:			  19 February 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	dict
PORTVERSION=	1.4.9
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.unc.edu/pub/users/faith/dict/ \
		ftp://ftp.dict.org/pub/dict/
DISTNAME=	${PORTNAME}d-${PORTVERSION}

MAINTAINER=	obrien@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-cflags=${CFLAGS}"
USE_GMAKE=	yes
ALL_TARGET=	dict
INSTALL_TARGET=	install.dict
MAN1=		dict.1

.include <bsd.port.mk>
