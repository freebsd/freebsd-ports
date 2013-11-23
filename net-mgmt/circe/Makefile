# Created by: Berkeley NAC-Team <circe-port-maintainers@bws.net.berkeley.edu>
# $FreeBSD$

PORTNAME=	circe
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://bws.berkeley.edu/ports/

MAINTAINER=	circe-port-maintainers@bws.net.berkeley.edu
COMMENT=	A captive portal-based network access control solution in perl

LICENSE=	BSD

RUN_DEPENDS=	p5-Net-IP-Match-XS>=0:${PORTSDIR}/net-mgmt/p5-Net-IP-Match-XS \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-Sys-Syslog>=0:${PORTSDIR}/sysutils/p5-Sys-Syslog \
		p5-TryCatch>=0:${PORTSDIR}/lang/p5-TryCatch \
		p5-Data-Validate-IP>=0:${PORTSDIR}/net-mgmt/p5-Data-Validate-IP \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-BerkeleyDB>=0:${PORTSDIR}/databases/p5-BerkeleyDB \
		p5-Crypt-CBC>=0:${PORTSDIR}/security/p5-Crypt-CBC \
		p5-Proc-PID-File>=0:${PORTSDIR}/devel/p5-Proc-PID-File

USES=		perl5

DIST_SUBDIR=	${PORTNAME}
WRKSRC=		${WRKDIR}

OPTIONS_DEFINE=	ENCRYPT
ENCRYPT_DESC=	Encrypt destination URL in redirection

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MENCRYPT}
RUN_DEPENDS+=	p5-Crypt-DES>=0:${PORTSDIR}/security/p5-Crypt-DES \
		p5-Crypt-OpenSSL-AES>=0:${PORTSDIR}/security/p5-Crypt-OpenSSL-AES
.endif

MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} -e 's|$$(SITE_PERL)|${PREFIX}/${SITE_PERL_REL}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|$$(SITE_PERL_REL)|${SITE_PERL_REL}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
