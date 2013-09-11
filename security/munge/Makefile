# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	munge
PORTVERSION=	0.5.10
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Authentication service for creating and validating credentials

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		perl5
USE_LDCONFIG=	yes
USE_RC_SUBR=	munged

MAN1=		unmunge.1 \
	       	munge.1 \
	       	remunge.1
MAN3=		munge.3 \
		munge_ctx_copy.3 \
	       	munge_ctx_get.3 \
	       	munge_ctx.3 \
	       	munge_enum_int_to_str.3 \
	       	munge_enum_is_valid.3 \
	       	munge_enum_str_to_int.3 \
	       	munge_enum.3
MAN7=		munge.7
MAN8=		munged.8
MLINKS=		munge.3 munge_strerror.3 \
		munge.3 munge_encode.3 \
		munge.3 munge_decode.3 \
	       	munge_ctx.3 munge_ctx_create.3 \
	       	munge_ctx.3 munge_ctx_destroy.3 \
		munge_ctx.3 munge_ctx_set.3 \
		munge_ctx.3 munge_ctx_strerror.3

.include <bsd.port.mk>
