# Created by: Zane C. Bowers
# $FreeBSD$

PORTNAME=	netident
PORTVERSION=	0.1.0
CATEGORIES=	sysutils deskutils
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Tool for helping identify what network a machine is on

RUN_DEPENDS=	p5-IO-Interface>=0:${PORTSDIR}/net/p5-IO-Interface \
		p5-Net-CIDR-Lite>=0:${PORTSDIR}/net/p5-Net-CIDR-Lite

USES=		perl5 shebangfix
SHEBANG_FILES=	*.pl
NO_WRKSUBDIR=	yes

MAN1=		${PORTNAME}.1

PLIST_FILES=	bin/${PORTNAME}
PLIST_DIRS=	etc/netident

post-extract:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	@${EXEC} pod2man --section=1 --release=${PORTVERSION} --name=${PORTNAME} --center=${PORTNAME}" user guide" ${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/${PORTNAME}.1
	@${CHMOD} +x ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} /var/db/netident/
	@${MKDIR} ${PREFIX}/etc/netident/

.include <bsd.port.mk>
