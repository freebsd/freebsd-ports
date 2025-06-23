PORTNAME=	bacnet-stack
PORTVERSION=	1.4.1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-apps

MAINTAINER=	acm@FreeBSD.org
COMMENT=	open source protocol stack for embedded systems (apps)
WWW=		https://github.com/bacnet-stack/bacnet-stack

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license/readme.txt

LIB_DEPENDS=	libdispatch.so:devel/libdispatch
RUN_DEPENDS=	bash:shells/bash

USES=		gmake compiler:c++11-lang localbase:ldflags shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	bacnet-stack
GH_TAGNAME=	c111154

LDFLAGS=	-lm

ALL_TARGET=	bsd

SHEBANG_LANG=	bash
SHEBANG_FILES=	bin/*.sh

BACNET_APPS=	bacabort bacackalarm bacale bacarf bacawf bacco bacdcc bacdo \
		bacepics bacerror bacevent bacge baciam baciamr bacinitr \
		bacnni bacpoll bacrbdt bacrd bacrfdt bacrle bacrp bacrpm bacrr \
		bacscov bacserv bacts bacucov bacuevent bacupt bacwbdt bacwh \
		bacwi bacwinn bacwir bacwp bacwpm
BACNET_SCRIPTS=	abort-reason.sh bacbbmd.sh bacroute.sh bacrpd.sh bvlc.sh \
		door-status.sh error-code.sh event-state.sh event-type.sh \
		lock-status.sh object-type.sh program-request.sh \
		program-state.sh property_id.sh property-states.sh \
		reliability.sh restart-reason.sh router-mstp.sh units.sh \
		vendor-id.sh

post-patch:
	@${REINPLACE_CMD} -i "" 's|\./bin/||g' ${WRKSRC}/bin/*.sh
	@${REINPLACE_CMD} -i "" 's|\./||g' ${WRKSRC}/bin/*.sh

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for FILE in ${BACNET_APPS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${FILE} ${STAGEDIR}${PREFIX}/bin/
.endfor

.for FILE in ${BACNET_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${FILE} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
