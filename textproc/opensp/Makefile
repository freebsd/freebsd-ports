# New ports collection makefile for:	OpenSP
# Date created:		Jan 6, 2003
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	OpenSP
PORTVERSION=	1.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openjade

MAINTAINER=	kuriyama@FreeBSD.org

USE_GMAKE=	YES
USE_LIBTOOL=	YES
USE_PERL5=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog \
		--datadir=${PREFIX}/share/sgml/openjade
INSTALLS_SHLIB=	yes

MAN1=	onsgmls.1 osgmlnorm.1 ospam.1 ospent.1 osx.1

.include <bsd.port.pre.mk>

# This port cannot be CFLAGS safe, using optimizations such as
# 'march=-mpentium -Os' produces core dumps with certain input files
# Therefore, we'd better remove all machine optimizations and any -O
# other than -O{0,1,}. Idea taken from palm/prc-tools-gcc.
CPPFLAGS:=	-O ${CFLAGS:N-O*:N-m*}

.include <bsd.port.post.mk>
