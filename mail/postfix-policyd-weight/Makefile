# Created by: Robert Felber <robtone@ek-muc.de>
# $FreeBSD$

PORTNAME=	policyd-weight
PORTVERSION=	0.1.15.1
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.policyd-weight.org/releases/ \
		LOCAL/ohauer
PKGNAMEPREFIX=	postfix-

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Weighted policy daemon for postfix

RUN_DEPENDS=	p5-Net-DNS>0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-IP>0:${PORTSDIR}/net-mgmt/p5-Net-IP

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}.conf.sample

USERS=		polw
GROUPS=		polw

USE_RC_SUBR+=	policyd-weight
USES=		perl5
NO_BUILD=	yes

MAN8+=	policyd-weight.8
MAN5+=	policyd-weight.conf.5

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
# really remove dead lists
# SFNET bug ID: 2765629, 3400804
# rfc-ignorant: all entrieys will be marked as deprecated starting on 2012-09-30
	@${REINPLACE_CMD} -e '/DSBL_ORG/d' -e '/IPv6_RBL/d' -e '/rfc-ignorant/d' \
		-e '/IX_MANITU/ s/,$$//' -e '/AHBL/ s/,$$//' \
		${WRKSRC}/policyd-weight ${WRKSRC}/policyd-weight.conf.sample

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${PREFIX}/etc/

	${INSTALL_MAN} ${WRKSRC}/man/man5/${MAN5} ${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/man/man8/${MAN8} ${PREFIX}/man/man8/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
