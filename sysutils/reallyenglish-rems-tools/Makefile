# $FreeBSD$

PORTNAME=	reallyenglish-rems-tools
PORTVERSION=	0.14
#PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.reallyenglish.com/${PORTNAME}/

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Local tools at reallyenglish, not available for public

RUN_DEPENDS=	${LOCALBASE}/sbin/send_nsca:net-mgmt/nsca-client

USE_PERL5=	Yes
USE_RC_SUBR=	varnisherrorlog
USES=	tar:tgz shebangfix
SHEBANG_FILES=	src/ezjail_available_ip/ezjail_available_ip.pl \
	src/htgrep/htgrep.pl \
	src/htgrep/htawk.pl

do-install:
	${MAKE} -C ${WRKSRC} install DESTDIR=${STAGEDIR}${PREFIX}
.include <bsd.port.mk>
