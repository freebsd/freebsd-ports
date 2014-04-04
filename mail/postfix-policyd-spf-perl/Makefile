# Created by: Darren Pilgrim <ports.maintainer@evilphi.com>
# $FreeBSD$

PORTNAME=	postfix-policyd-spf-perl
PORTVERSION=	2.007
CATEGORIES=	mail
MASTER_SITES=	http://www.openspf.org/blobs/

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	SPF policy service for Postfix written in Perl

RUN_DEPENDS=	p5-Mail-SPF>=0:${PORTSDIR}/mail/p5-Mail-SPF \
		p5-NetAddr-IP>=4:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		p5-version>=0:${PORTSDIR}/devel/p5-version

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes

PLIST_FILES=	sbin/postfix-policyd-spf-perl

SUB_LIST=	PREFIX=${PREFIX}
SUB_FILES=	pkg-message

SPF_FAIL?=	550
SPF_TEMPERROR?=	DEFER_IF_PERMIT
REINPLACE=	s/%%SPF_FAIL%%/${SPF_FAIL}/g;\
		s/%%SPF_TEMPERROR%%/${SPF_TEMPERROR}/g;

pre-patch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can change the actions returned by the server by setting the following"
	@${ECHO_MSG} "environment variables:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  SPF_FAIL      - Used when the SPF record(s) determine client is not"
	@${ECHO_MSG} "                  authorized.  Default: 550"
	@${ECHO_MSG} "  SPF_TEMPERROR - Used when the SPF check itself fails due to a transient"
	@${ECHO_MSG} "                  error (i.e. DNS timeout).  Default: DEFER_IF_PERMIT"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e '${REINPLACE}' ${WRKSRC}/postfix-policyd-spf-perl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/postfix-policyd-spf-perl ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
