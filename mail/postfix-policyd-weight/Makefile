# Created by: Robert Felber <robtone@ek-muc.de>
# $FreeBSD$

PORTNAME=	policyd-weight
PORTVERSION=	0.1.15.1
PORTREVISION=	3
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
		man/man8/policyd-weight.8.gz \

USERS=		polw
GROUPS=		polw

USE_RC_SUBR+=	policyd-weight
USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes

.include <bsd.port.pre.mk>

post-patch:
# really remove dead lists
# SFNET bug ID: 2765629, 3400804
# rfc-ignorant: all entrieys will be marked as deprecated starting on 2012-09-30
# njabl.org: NJABL is offline
	@${REINPLACE_CMD} -e '/DSBL_ORG/d' -e '/IPv6_RBL/d' -e '/rfc-ignorant/d' \
		-e '/BL_NJABL/d' -e '/IX_MANITU/ s/,$$//' -e '/AHBL/ s/,$$//' \
		${WRKSRC}/policyd-weight ${WRKSRC}/policyd-weight.conf.sample

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/man/man5/policyd-weight.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/man/man8/policyd-weight.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.post.mk>
