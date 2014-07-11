# Created by: Joe Barbish
# $FreeBSD$

PORTNAME=	qjail
PORTVERSION=	3.5
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	qjail@a1poweruser.com
COMMENT=	Utility to quickly deploy and manage jails

USES=		tar:bzip2
NO_BUILD=	yes

CONFLICTS_INSTALL=	qjail-2.* qjail-3.0 qjail-3.1 

do-install:
.for i in qjail qjail.vnet.be qjail.vnet.ng
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/qjail.bootime              \
		${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA}   ${WRKSRC}/qjail.portsnap.conf        \
		${STAGEDIR}${PREFIX}/etc
.for i in qjail qjail-intro qjail-howto
	${INSTALL_MAN}   ${WRKSRC}/${i}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
.endfor

# note examples are mandatory. qjail will not function without them
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ \
	    && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
