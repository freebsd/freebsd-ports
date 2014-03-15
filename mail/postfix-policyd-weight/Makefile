# Created by: Robert Felber <robtone@ek-muc.de>
# $FreeBSD$

PORTNAME=	policyd-weight
PORTVERSION=	0.1.15.2
CATEGORIES=	mail
MASTER_SITES=	http://www.policyd-weight.org/releases/ \
		LOCAL/ohauer
PKGNAMEPREFIX=	postfix-

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Weighted policy daemon for postfix

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-DNS>0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-IP>0:${PORTSDIR}/net-mgmt/p5-Net-IP

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}.conf.sample \
		man/man5/policyd-weight.conf.5.gz \
		man/man8/policyd-weight.8.gz

USERS=		polw
GROUPS=		polw

USE_RC_SUBR+=	policyd-weight
USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} -m 644 ${WRKSRC}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/man/man5/policyd-weight.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/man/man8/policyd-weight.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
