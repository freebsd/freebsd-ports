PORTNAME=	nut
PORTVERSION=	2.8.0
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.networkupstools.org/source/${PORTVERSION:R}/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Network UPS Tools

LICENSE=	GPLv2+ GPLv3+ ART10 GPLv1+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	nut-devel-*

GNU_CONFIGURE=	yes
USES=		autoreconf:build compiler:c11 gmake libtool pkgconfig python:build
USE_LDCONFIG=	yes

NUT_USER?=	uucp
NUT_GROUP?=	uucp
STATEDIR?=	/var/db/nut
PLIST_SUB+=	NUT_USER=${NUT_USER}
PLIST_SUB+=	NUT_GROUP=${NUT_GROUP}
CGIDIR?=	${PREFIX}/www/cgi-bin/${PORTNAME}
CGIDIR_REL?=	${CGIDIR:S,^${PREFIX}/,,}
PLIST_SUB+=	CGIDIR="${CGIDIR_REL}"
PLIST_SUB+=	CGIETCDIR="etc/nut/"

OPTIONS_DEFAULT=SERIAL USB SNMP NEON PDU MODBUS CGI BASH AVAHI FREEIPMI DOCS MANPAGES OPENSSL
OPTIONS_DEFINE=	SERIAL USB SNMP NEON PDU MODBUS CGI BASH AVAHI IPMIPSU FREEIPMI DOCS MANPAGES
OPTIONS_SINGLE=	IPMI SSL
OPTIONS_SINGLE_SSL=	SSL_OFF OPENSSL NSS
OPTIONS_SUB=	yes

SERIAL_DESC=	SERIAL support
USB_DESC=	USB support
NEON_DESC=	NEON XML/HTTP support
PDU_DESC=	Powerman PDU support
MODBUS_DESC=	Modbus support
CGI_DESC=	Web CGI interface
FREEIPMI_DESC=	freeipmi support
IPMIPSU_DESC=	Use nut-ipmipsu support (experimental)
SSL_OFF_DESC=	No SSL support

USE_RC_SUBR=	nut nut_upsmon nut_upslog
SUB_LIST+=	STATEDIR=${STATEDIR}
PLIST_SUB+=	STATEDIR=${STATEDIR}

PORTDOCS=	*

TMPDIR?=	/tmp
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/nut \
		--program-transform-name="" \
		--localstatedir=${STATEDIR} \
		--datadir=${PREFIX}/etc/nut \
		--with-devd-dir=${PREFIX}/etc/devd \
		--with-drvpath=${PREFIX}/libexec/nut \
		--with-statepath=${STATEDIR} \
		--with-altpidpath=${STATEDIR} \
		--with-pidpath=${STATEDIR} \
		--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig \
		--with-user=${NUT_USER} \
		--with-group=${NUT_GROUP} \
		--with-dev

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LIB_DEPENDS+=	libltdl.so:devel/libltdl

MANPAGES_CONFIGURE_ON=	--with-doc=man=auto
MANPAGES_CONFIGURE_OFF=	--with-doc=no

CGI_LIB_DEPENDS=	libgd.so:graphics/gd
CGI_CONFIGURE_WITH=	cgi
CGI_CONFIGURE_ON=	--with-cgipath=${CGIDIR} \
			--with-htmlpath=${WWWDIR} \
			--with-gd-includes=-I${LOCALBASE}/include \
			--with-gd-libs="-L${LOCALBASE}/lib -lgd"

SERIAL_CONFIGURE_WITH=	serial

USB_CONFIGURE_WITH=	usb=auto

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=	snmp

NEON_LIB_DEPENDS+=	libneon.so:www/neon
NEON_CONFIGURE_WITH=	neon

PDU_LIB_DEPENDS+=	libpowerman.so:sysutils/powerman
PDU_CONFIGURE_WITH=	powerman

MODBUS_LIB_DEPENDS+=	libmodbus.so:comms/libmodbus
MODBUS_CONFIGURE_WITH=	modbus

BASH_BUILD_DEPENDS=	${LOCALBASE}/share/bash-completion/bash_completion.sh:shells/bash-completion
BASH_RUN_DEPENDS=	${LOCALBASE}/share/bash-completion/bash_completion.sh:shells/bash-completion

AVAHI_BUILD_DEPENDS=	${LOCALBASE}/include/avahi-ui/avahi-ui.h:net/avahi-header
AVAHI_BUILD_DEPENDS=	avahi-daemon:net/avahi-app
AVAHI_RUN_DEPENDS=	avahi-daemon:net/avahi-app
AVAHI_CONFIGURE_WITH=	avahi

FREEIPMI_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi
FREEIPMI_CONFIGURE_WITH=freeipmi

IPMIPSU_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi
IPMIPSU_CONFIGURE_WITH=	ipmi

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_WITH=	openssl

NSS_LIB_DEPENDS=	libnss3.so:security/nss
NSS_CONFIGURE_WITH=	nss

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -i '' -e 's|/usr/bin/env python|${PYTHON_CMD}|'
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -i '' -e 's|/usr/local/ups|${PREFIX}|'

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nut

post-install:
	@${MKDIR} ${STAGEDIR}${STATEDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/syslog.d
.if ${PORT_OPTIONS:MBASH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${WRKSRC}/scripts/misc/nut.bash_completion ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/cables/*.txt ${STAGEDIR}${DOCSDIR}/cables
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ.txt ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS COPYING ChangeLog INSTALL MAINTAINERS NEWS README UPGRADING
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PATCHDIR}/nut.syslog ${STAGEDIR}${EXAMPLESDIR}/syslog.sample
	${INSTALL_DATA} ${PATCHDIR}/nut.newsyslog ${STAGEDIR}${EXAMPLESDIR}/newsyslog.sample
	${MKDIR} ${STAGEDIR}/var/log/nut
	@${RM} ${STAGEDIR}${PREFIX}/etc/nut/solaris-init/nut
	@${RMDIR} ${STAGEDIR}${PREFIX}/etc/nut/solaris-init

.include <bsd.port.post.mk>
