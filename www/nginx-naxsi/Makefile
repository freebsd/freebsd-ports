# Created by: Bartek Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nginx
PKGNAMESUFFIX=	-naxsi

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Robust and small WWW server (plus NAXSI)

MASTERDIR=	${.CURDIR}/../nginx

CONFLICTS=	nginx-1.* \
		nginx-devel-1.* \
		nginx-full-1.* \
                nginx-lite-1.*

OPTIONS_DEFAULT?=DSO FILE_AIO HTTP HTTP_ADDITION HTTP_AUTH_REQ HTTP_CACHE \
                HTTP_DAV HTTP_FLV HTTP_GZIP_STATIC HTTP_GUNZIP_FILTER \
                HTTP_MP4 HTTP_RANDOM_INDEX HTTP_REALIP HTTP_SECURE_LINK \
                HTTP_SLICE HTTP_REWRITE HTTP_SSL HTTP_STATUS HTTP_SUB \
                HTTPV2 MAIL MAIL_SSL NAXSI STREAM STREAM_SSL THREADS WWW

.include "${MASTERDIR}/Makefile"
