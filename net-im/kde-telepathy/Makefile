# $FreeBSD$

PORTNAME=	kde-telepathy
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net-im kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE integrated instant messaging framework

RUN_DEPENDS=	ktp-accounts-kcm>=${KDE_APPLICATIONS_VERSION}:net-im/ktp-accounts-kcm \
		ktp-approver>=${KDE_APPLICATIONS_VERSION}:net-im/ktp-approver \
		ktp-auth-handler>=${KDE_APPLICATIONS_VERSION}:net-im/ktp-auth-handler \
		ktp-contact-list>=${KDE_APPLICATIONS_VERSION}:net-im/ktp-contact-list \
		ktp-contact-runner>=${KDE_APPLICATIONS_VERSION}:net-im/ktp-contact-runner \
		ktp-filetransfer-handler>=${KDE_APPLICATIONS_VERSION}:net-im/ktp-filetransfer-handler \
		ktp-kded-module>=${KDE_APPLICATIONS_VERSION}:net-im/ktp-kded-module \
		ktp-text-ui>=${KDE_APPLICATIONS_VERSION}:net-im/ktp-text-ui

USES=		metaport kde:5

OPTIONS_DEFINE=		CALL_UI PLASMA SEND_FILE
OPTIONS_DEFAULT=	PLASMA SEND_FILE

CALL_UI_DESC=		Voice/Video Call UI for Telepathy
CALL_UI_RUN_DEPENDS=	ktp-dialout-ui>=${KDE_APPLICATIONS_VERSION}:net-im/ktp-call-ui

PLASMA_DESC=		Applets for KDE Plasma Desktop integration
PLASMA_RUN_DEPENDS=	ktp-desktop-applets>=${KDE_APPLICATIONS_VERSION}:net-im/ktp-desktop-applets

SEND_FILE_DESC=		Context menu plugin for sending files
SEND_FILE_RUN_DEPENDS=	ktp-send-file>=${KDE_APPLICATIONS_VERSION}:net-im/ktp-send-file

.include <bsd.port.mk>
