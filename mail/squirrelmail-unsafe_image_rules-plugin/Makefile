# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unsafe_image_rules
PORTVERSION=	0.8
PORTREVISION=	1
DISTNAME=	${PORTNAME:S/-/_/}.${PORTVERSION}-1.4
DIST_SUBDIR=	squirrelmail

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Determines what unsafe (web) images will be shown

USE_SM_COMPAT=	yes
USE_PERL5_RUN=	yes

SQUIRREL_PLUGIN_NAME=	${PORTNAME:S/-/_/}

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"

.include <bsd.port.mk>
