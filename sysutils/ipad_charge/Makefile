# $FreeBSD$

PORTNAME=	ipad_charge
PORTVERSION=	2.0.1
CATEGORIES=	sysutils
DISTFILES=	# empty

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Generic iPad USB charging utility

LICENSE=	BSD

USE_RC_SUBR=	ipad_charge
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires FreeBSD 8.0-RELEASE or later
.endif

do-install:

post-install:
	@${MKDIR} ${PREFIX}/etc/devd
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		< ${FILESDIR}/ipad_charge.conf.in > ${WRKDIR}/ipad_charge.conf
	${INSTALL_DATA} "${WRKDIR}/ipad_charge.conf" ${PREFIX}/etc/devd
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
