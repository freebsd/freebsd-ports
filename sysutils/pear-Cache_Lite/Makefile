# Ports collection makefile for:  pear-Cache_Lite
# Date created:			  26 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Cache_Lite
PORTVERSION=	1.7.8
PORTEPOCH=	1
CATEGORIES=	sysutils www pear

MAINTAINER=	wenheping@gmail.com
COMMENT=	PEAR fast and safe little cache system

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Cache
FILES=		Lite/Output.php Lite/Function.php Lite/File.php Lite.php
DOCS=		docs/technical docs/examples LICENSE TODO
TESTS=		Cache_Lite_File_classical.phpt Cache_Lite_Function_classical.phpt \
		Cache_Lite_Function_dontcache.phpt Cache_Lite_Function_drop.phpt \
		Cache_Lite_Output_classical.phpt Cache_Lite_automaticCleaning.phpt \
		Cache_Lite_classical.phpt Cache_Lite_error.phpt \
		Cache_Lite_error2.phpt Cache_Lite_error3.phpt \
		Cache_Lite_eternal.phpt Cache_Lite_fatest.phpt \
		Cache_Lite_hashed.phpt Cache_Lite_lifetime.phpt \
		Cache_Lite_memorycache.phpt Cache_Lite_serialization.phpt \
		bench.php bench2.php \
		bench3.php cache_lite_base.inc \
		cache_lite_file_base.inc cache_lite_function_base.inc \
		cache_lite_output_base.inc callcache.inc \
		pearbug13693.phpt pearbug513.phpt \
		pearbug7618.phpt readme \
		tmpdir.inc
_DOCSDIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
