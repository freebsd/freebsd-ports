PORTNAME=	subnetcalc
DISTVERSION=	2.6.5
CATEGORIES=	net
MASTER_SITES=	https://www.nntb.no/~dreibh/subnetcalc/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	IPv4/IPv6 Subnet Calculator
WWW=		https://www.nntb.no/~dreibh/subnetcalc/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake gettext tar:xz

PLIST_FILES=	bin/subnetcalc \
		share/bash-completion/completions/subnetcalc \
		share/locale/de/LC_MESSAGES/subnetcalc.mo \
		share/locale/nb/LC_MESSAGES/subnetcalc.mo \
		share/man/man1/subnetcalc.1.gz

.include <bsd.port.mk>
