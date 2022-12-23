PORTNAME=	postfix-policyd-spf-perl
PORTVERSION=	2.011
CATEGORIES=	mail
MASTER_SITES=	https://launchpad.net/postfix-policyd-spf-perl/trunk/${PORTVERSION}/+download/

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	SPF policy service for Postfix written in Perl
WWW=		https://launchpad.net/postfix-policyd-spf-perl/

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Mail-SPF>=2.006:mail/p5-Mail-SPF \
		p5-NetAddr-IP>=4:net-mgmt/p5-NetAddr-IP \
		p5-Sys-Hostname-Long>=0:sysutils/p5-Sys-Hostname-Long

USES=		perl5 shebangfix
USE_PERL5=	run

SHEBANG_FILES=	postfix-policyd-spf-perl

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PREFIX=${PREFIX}

PLIST_FILES=	libexec/postfix-policyd-spf-perl

SPF_FAIL?=	550
SPF_TEMPERROR?=	DEFER_IF_PERMIT
REINPLACE=	s/%%SPF_FAIL%%/${SPF_FAIL}/g; \
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
	${INSTALL_SCRIPT} ${WRKSRC}/postfix-policyd-spf-perl ${STAGEDIR}${PREFIX}/libexec

.include <bsd.port.mk>
