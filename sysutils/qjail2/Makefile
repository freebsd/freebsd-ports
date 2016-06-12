# Created by: Joe Barbish
# $FreeBSD$

PORTNAME=	qjail
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to quickly deploy and manage jails

USES=		tar:bzip2
NO_BUILD=	yes

CONFLICTS_INSTALL=	qjail-1.* qjail-3.*

do-install:

	${INSTALL_SCRIPT} ${WRKSRC}/qjail		\
		${STAGEDIR}${PREFIX}/bin

.for i in qjail2 qjail-jail2
	${INSTALL_SCRIPT} ${WRKSRC}/${i}		\
		${STAGEDIR}${PREFIX}/etc/rc.d
.endfor

.for i in qjail.conf.sample qjail.portsnap.conf
	${INSTALL_DATA}   ${WRKSRC}/${i}		\
		${STAGEDIR}${PREFIX}/etc
.endfor

.for i in qjail qjail-intro qjail.conf qjail-howto
	${INSTALL_MAN}    ${WRKSRC}/${i}.8		\
		${STAGEDIR}${MAN8PREFIX}/man/man8
.endfor

# note examples are mandatory. qjail will not function without them
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/			\
	&& ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
