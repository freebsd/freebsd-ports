# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>
# $FreeBSD$

PKGNAMESUFFIX=	4-rails41

DEPRECATED=	Rails 4.1 is no longer supported - please switch to Rails 4.2
EXPIRATION_DATE=	2016-03-31

RUN_DEPENDS=	rubygem-railties41>=4.1.12:${PORTSDIR}/www/rubygem-railties41 \
		rubygem-sass32>=3.2.2:${PORTSDIR}/textproc/rubygem-sass32 \
		rubygem-sprockets>=2.8:${PORTSDIR}/devel/rubygem-sprockets \
		rubygem-sprockets-rails-rails41>=2.0:${PORTSDIR}/devel/rubygem-sprockets-rails-rails41

MASTERDIR=	${.CURDIR}/../rubygem-sass-rails4

.include "${MASTERDIR}/Makefile"
