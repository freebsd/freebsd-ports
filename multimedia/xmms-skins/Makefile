# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	xmms-skins
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.lissyara.su/distfiles/
DISTFILES=	AbsoluteE_Xmms.zip \
		Absolute_Blue-XMMS.zip \
		AdamAmp.zip \
		Apple_Platinum_Amp.zip \
		Aqua.zip \
		BlackXMMS.zip \
		BlueIce.zip \
		BlueSteel.zip \
		BlueSteel_xmms.zip \
		BrushedMetal_Xmms.zip \
		CX2.zip \
		Cobalt-Obscura.tar.gz \
		ColderXMMS.tar.gz \
		ConceptX-Gold.zip \
		Concept_X.zip \
		Coolblue.tar.gz \
		Covenant.zip \
		Cyrus-XMMS.zip \
		Eclipse.tar.gz \
		FB_1.2.zip \
		FB_2.1.zip \
		FreeBSD.zip \
		Freshmeat_Amp.zip \
		GTK+.zip \
		Ghost-10.zip \
		HeliXMMS.zip \
		Inverse.zip \
		LinuxDotCom.tar.gz \
		Marble.zip \
		MarbleX.tar.gz \
		NeXTAmp2-1.0pre1.zip \
		NeXTAmp2.4.zip \
		NoerdAmp-SE.tar.gz \
		OmniAMP-1.3.zip \
		Panic.zip \
		Plume-XMMS-v1.zip \
		SuedE.zip \
		Ultrafina-pw.zip \
		Ultrafina.zip \
		Ultrafina2000.zip \
		UltrafinaSE.zip \
		UltrafinaSEM.zip \
		Vegetal_Blues.zip \
		Vegetali_1-1.zip \
		Vulcan.zip \
		Vulcan21.zip \
		Winamp_X_XMMS_1.01.tar.gz \
		WoodPanel.zip \
		X-Tra.zip \
		XMMS-AfterStep.zip \
		XMMS-Green.zip \
		XawMMS.zip \
		arctic_Xmms.zip \
		blackstar.zip \
		blueHeart-xmms-20.zip \
		blueHeart_Xmms.zip \
		bmXmms.zip \
		cart0onix.zip \
		chaos_XMMS.zip \
		cherry.zip \
		cherry_best.tar.gz \
		cracked.zip \
		detone_blue.zip \
		detone_green.zip \
		eMac-XMMS.zip \
		eMac_Xmms_color_schemes.zip \
		fiRe.tar.gz \
		fyre.zip \
		gLaNDAmp-2.0.zip \
		m2n.tar.gz \
		maXMMS.tar.gz \
		minEguE-xmms-v2.zip \
		myway.zip \
		nixamp2.tar.gz \
		nuance-2.0.zip \
		nuance-green-2.0.zip \
		sinistar.zip \
		spiffMEDIA.zip \
		sword.tar.gz \
		titanium.zip \
		xmmearth.tar.gz \
		xmms-256.zip
EXTRACT_ONLY=

MAINTAINER=	admin@lissyara.su
COMMENT=	Skins for X Multimedia System (XMMS)

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

CONFLICTS_INSTALL=	xmms-skins-huge-*

NO_BUILD=	yes
DATADIR=	${PREFIX}/share/xmms
PLIST_FILES=	${DISTFILES:S,^,${DATADIR_REL}/Skins/,}
PLIST_DIRSTRY=	${DATADIR_REL}/Skins ${DATADIR_REL}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/Skins
	${INSTALL_DATA} ${DISTFILES:S,^,${DISTDIR}/,} ${STAGEDIR}${DATADIR}/Skins

.include <bsd.port.mk>
