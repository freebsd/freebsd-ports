# New ports collection makefile for:		swatch
# Date created:					May 2 97
# Whom:						jfitz
#
# $FreeBSD$
#

PORTNAME=	swatch
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	swatch

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	The Simple WATCHer and filter

BUILD_DEPENDS=	${BUILD_DEPENDS_56} \
	${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLMAN1DIR=${PREFIX}/man/man1
USE_RC_SUBR=	yes

MAN1=	swatch.1
MAN3=	Swatch::Actions.3 Swatch::Throttle.3 Swatch::Threshold.3

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

post-patch:
	${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/swatch.sh > ${WRKSRC}/swatch.sh
	${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/swatch.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
