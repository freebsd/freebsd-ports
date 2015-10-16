# Created by: Dereckson <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	rhc
PORTVERSION=	1.32.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	dereckson@gmail.com
COMMENT=	Administration console client for RedHat OpenShift

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/minitar:${PORTSDIR}/archivers/rubygem-archive-tar-minitar \
		${LOCALBASE}/bin/commander:${PORTSDIR}/devel/rubygem-commander \
		rubygem-highline>=1.6.11:${PORTSDIR}/devel/rubygem-highline \
		rubygem-httpclient>=2.4:${PORTSDIR}/www/rubygem-httpclient \
		rubygem-net-scp>=1.1.2:${PORTSDIR}/security/rubygem-net-scp \
		rubygem-net-ssh>=2.0.11:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-net-ssh-multi>=1.2.0:${PORTSDIR}/security/rubygem-net-ssh-multi \
		rubygem-open4>0:${PORTSDIR}/devel/rubygem-open4

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rhc

.include <bsd.port.mk>
