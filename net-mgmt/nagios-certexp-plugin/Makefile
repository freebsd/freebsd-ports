# Created by: ecronin@gizmolabs.org
# $FreeBSD$

PORTNAME=	nagios-certexp-plugin
PORTVERSION=	1.9
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.jhweiss.de/pub/users/weiss/nagios/plugins/
DISTNAME=	check_certexp.pl
EXTRACT_SUFX=

MAINTAINER=	ecronin@gizmolabs.org
COMMENT=	Nagios plugin for checking SSL server certificate expiration

LICENSE=	GPLv2+

RUN_DEPENDS+=	p5-Net-SSLeay>=0:security/p5-Net-SSLeay \
		p5-Date-Manip>=0:devel/p5-Date-Manip

USES=		perl5 shebangfix
NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	check_certexp.pl
PLIST_FILES=	${NAGIOS_PLUGIN_DIR}/check_certexp.pl

NAGIOS_PLUGIN_DIR=	libexec/nagios

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/check_certexp.pl

post-patch:
	${REINPLACE_CMD} -e \
		"s,/usr/local/nagios/libexec,${PREFIX}/${NAGIOS_PLUGIN_DIR}," \
		${WRKSRC}/check_certexp.pl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${NAGIOS_PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/check_certexp.pl ${STAGEDIR}${PREFIX}/${NAGIOS_PLUGIN_DIR}

.include <bsd.port.mk>
