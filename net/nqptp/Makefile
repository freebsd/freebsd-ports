PORTNAME=	nqptp
DISTVERSION=	1.2.8
CATEGORIES=	net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Not Quite PTP
WWW=		https://github.com/mikebrady/nqptp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	mikebrady

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/nqptp \
		etc/rc.d/nqptp \
		share/man/man8/nqptp.8.gz

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nqptp.freebsd \
		${STAGEDIR}$/${PREFIX}/etc/rc.d/${PORTNAME}

.include <bsd.port.mk>
