PORTNAME=	sendsms
PORTVERSION=	0.2.4
CATEGORIES=	net perl5
MASTER_SITES=	http://caspian.dotconf.net/menu/Software/SendSMS/ \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/
DISTNAME=	sendSMS.pl
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple perl command-line utility to send SMS via from on provider site

EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${PORTNAME}

PLIST_FILES=	bin/sendsms

CONFLICTS=	gnokii smstools

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
