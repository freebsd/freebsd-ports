# ex:ts=8
# Ports collection makefile for:  dict
# Date created:			  19 February 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	dict
PORTVERSION=	1.5.5
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.unc.edu/pub/users/faith/dict/ \
		ftp://ftp.dict.org/pub/dict/
DISTNAME=	${PORTNAME}d-${PORTVERSION}

MAINTAINER=	dd@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-local-zlib --with-cflags="${CFLAGS}" \
		--with-etcdir=${PREFIX}/etc
USE_GMAKE=	yes
ALL_TARGET=	dict
INSTALL_TARGET=	install.dict
MAN1=		dict.1

post-patch:
	${PERL} -pi.orig -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/dict.1

.include <bsd.port.mk>
