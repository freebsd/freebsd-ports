# Created by: Joe Barbish
# $FreeBSD$

PORTNAME=	qjail
PORTVERSION=	3.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	qjail@a1poweruser.com
COMMENT=	Utility to quickly deploy and manage jails

USE_BZIP2=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

MAN8=		qjail.8 qjail-intro.8 qjail-howto.8

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|'
	@${FIND} ${WRKSRC}/examples -name '*.bak' -delete

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/qjail ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/qjail.vnet.be ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/qjail.vnet.ng ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/qjail.bootime ${PREFIX}/etc/rc.d
	@${INSTALL_DATA}   ${WRKSRC}/qjail.portsnap.conf ${PREFIX}/etc
.for i in qjail qjail-intro qjail-howto
	@${INSTALL_MAN}    ${WRKSRC}/${i}.8 ${MAN8PREFIX}/man/man8
.endfor
# note examples are mandatory. qjail will not function without them
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ \
	    && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

# Note: Has to be done this way or package version will not contain any
# comments added with @${ECHO_MSG} command.
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
