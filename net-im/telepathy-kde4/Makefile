# $FreeBSD$

PORTNAME=	telepathy
PORTVERSION=	${KTP_VERSION}
PORTREVISION=	4
CATEGORIES=	net-im kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE integrated instant messaging framework

RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/kcm_ktp_accounts.so:net-im/ktp-accounts-kcm-kde4 \
		${KDE_PREFIX}/lib/kde4/kded_ktp_approver.so:net-im/ktp-approver-kde4 \
		${KDE_PREFIX}/lib/kde4/libexec/ktp-auth-handler:net-im/ktp-auth-handler-kde4 \
		${KDE_PREFIX}/bin/ktp-contactlist:net-im/ktp-contact-list-kde4 \
		${KDE_PREFIX}/lib/kde4/krunner_ktp_contacts.so:net-im/ktp-contact-runner-kde4 \
		${KDE_PREFIX}/lib/kde4/libexec/ktp-filetransfer-handler:net-im/ktp-filetransfer-handler-kde4 \
		${KDE_PREFIX}/lib/kde4/kded_ktp_integration_module.so:net-im/ktp-kded-integration-module-kde4 \
		${KDE_PREFIX}/lib/kde4/libexec/ktp-text-ui:net-im/ktp-text-ui-kde4

USES=		kde:4 metaport

OPTIONS_DEFINE=	PLASMA SEND_FILE
OPTIONS_DEFAULT=PLASMA SEND_FILE

PLASMA_DESC=	Applets for KDE Plasma Desktop integration
SEND_FILE_DESC=	Context menu plugin for sending files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLASMA}
RUN_DEPENDS+=	${KDE_PREFIX}/lib/kde4/plasma_applet_ktp_presence.so:net-im/plasma-applet-ktp-kde4
.endif

.if ${PORT_OPTIONS:MSEND_FILE}
RUN_DEPENDS+=	${KDE_PREFIX}/bin/ktp-send-file:net-im/ktp-send-file-kde4
.endif

.include <bsd.port.mk>
