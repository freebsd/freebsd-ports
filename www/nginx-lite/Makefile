PORTNAME=	nginx
PORTREVISION=	0
PKGNAMESUFFIX=	-lite

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Robust and small WWW server (lite package)

# Slave port of www/nginx (stable branch); mainline is www/nginx-devel.
# repology measures the flavored slave ports against mainline and reports them
# as outdated, while unflavored www/nginx with the same version is not.

MASTERDIR=	${.CURDIR}/../nginx

CONFLICTS=	nginx-1.* \
		nginx-devel-1.* \
                nginx-full-1.* \
                nginx-naxsi-1.*

OPTIONS_DEFAULT=FILE_AIO HTTP HTTP_CACHE \
		HTTP_REALIP HTTP_REWRITE \
		HTTP_SSL THREADS PCRE_ONE

.include "${MASTERDIR}/Makefile"
