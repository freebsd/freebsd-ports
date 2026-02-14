PORTNAME=	nerd-fonts
DISTVERSION=	3.4.0
PORTREVISION?=	1
CATEGORIES=	x11-fonts

MAINTAINER=	bsdcode@disroot.org
WWW=		https://www.nerdfonts.com

.if defined(MASTERDIR) && ${MASTERDIR} != ${.CURDIR}

_NAME?=		${DISTNAME}

MASTER_SITES=	https://github.com/ryanoasis/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-${_NAME:tl}
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

COMMENT=	${_NAME} Nerd Font

USES=		fonts tar:xz
FONTNAME=	${PORTNAME}/${_NAME}

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST=		${.CURDIR}/pkg-plist
DISTINFO_FILE=	${.CURDIR}/distinfo

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${FONTSDIR} '-regex .*\.otf -o -regex .*\.ttf')

.else

COMMENT=	Meta-port for all Nerd Fonts

RUN_DEPENDS=	nerd-fonts-0xproto>0:x11-fonts/nerd-fonts-0xproto \
		nerd-fonts-3270>0:x11-fonts/nerd-fonts-3270 \
		nerd-fonts-adwaitamono>0:x11-fonts/nerd-fonts-adwaitamono \
		nerd-fonts-agave>0:x11-fonts/nerd-fonts-agave \
		nerd-fonts-anonymicepro>0:x11-fonts/nerd-fonts-anonymicepro \
		nerd-fonts-arimo>0:x11-fonts/nerd-fonts-arimo \
		nerd-fonts-atkynsonmono>0:x11-fonts/nerd-fonts-atkynsonmono \
		nerd-fonts-aurulentsansmono>0:x11-fonts/nerd-fonts-aurulentsansmono \
		nerd-fonts-bigblueterminal>0:x11-fonts/nerd-fonts-bigblueterminal \
		nerd-fonts-bitstromwera>0:x11-fonts/nerd-fonts-bitstromwera \
		nerd-fonts-blexmono>0:x11-fonts/nerd-fonts-blexmono \
		nerd-fonts-caskaydiacove>0:x11-fonts/nerd-fonts-caskaydiacove \
		nerd-fonts-caskaydiamono>0:x11-fonts/nerd-fonts-caskaydiamono \
		nerd-fonts-codenewroman>0:x11-fonts/nerd-fonts-codenewroman \
		nerd-fonts-comicshannsmono>0:x11-fonts/nerd-fonts-comicshannsmono \
		nerd-fonts-commitmono>0:x11-fonts/nerd-fonts-commitmono \
		nerd-fonts-cousine>0:x11-fonts/nerd-fonts-cousine \
		nerd-fonts-d2coding>0:x11-fonts/nerd-fonts-d2coding \
		nerd-fonts-daddytimemono>0:x11-fonts/nerd-fonts-daddytimemono \
		nerd-fonts-dejavusansmono>0:x11-fonts/nerd-fonts-dejavusansmono \
		nerd-fonts-departuremono>0:x11-fonts/nerd-fonts-departuremono \
		nerd-fonts-droidsansmono>0:x11-fonts/nerd-fonts-droidsansmono \
		nerd-fonts-envycoder>0:x11-fonts/nerd-fonts-envycoder \
		nerd-fonts-fantasquesansmono>0:x11-fonts/nerd-fonts-fantasquesansmono \
		nerd-fonts-firacode>0:x11-fonts/nerd-fonts-firacode \
		nerd-fonts-firamono>0:x11-fonts/nerd-fonts-firamono \
		nerd-fonts-geistmono>0:x11-fonts/nerd-fonts-geistmono \
		nerd-fonts-gohu>0:x11-fonts/nerd-fonts-gohu \
		nerd-fonts-gomono>0:x11-fonts/nerd-fonts-gomono \
		nerd-fonts-hack>0:x11-fonts/nerd-fonts-hack \
		nerd-fonts-hasklug>0:x11-fonts/nerd-fonts-hasklug \
		nerd-fonts-heavydata>0:x11-fonts/nerd-fonts-heavydata \
		nerd-fonts-hurmit>0:x11-fonts/nerd-fonts-hurmit \
		nerd-fonts-imwriting>0:x11-fonts/nerd-fonts-imwriting \
		nerd-fonts-inconsolata>0:x11-fonts/nerd-fonts-inconsolata \
		nerd-fonts-inconsolatago>0:x11-fonts/nerd-fonts-inconsolatago \
		nerd-fonts-inconsolatalgc>0:x11-fonts/nerd-fonts-inconsolatalgc \
		nerd-fonts-intonemono>0:x11-fonts/nerd-fonts-intonemono \
		nerd-fonts-iosevka>0:x11-fonts/nerd-fonts-iosevka \
		nerd-fonts-iosevkaterm>0:x11-fonts/nerd-fonts-iosevkaterm \
		nerd-fonts-iosevkatermslab>0:x11-fonts/nerd-fonts-iosevkatermslab \
		nerd-fonts-jetbrainsmono>0:x11-fonts/nerd-fonts-jetbrainsmono \
		nerd-fonts-lekton>0:x11-fonts/nerd-fonts-lekton \
		nerd-fonts-lilex>0:x11-fonts/nerd-fonts-lilex \
		nerd-fonts-literation>0:x11-fonts/nerd-fonts-literation \
		nerd-fonts-martianmono>0:x11-fonts/nerd-fonts-martianmono \
		nerd-fonts-meslo>0:x11-fonts/nerd-fonts-meslo \
		nerd-fonts-monaspice>0:x11-fonts/nerd-fonts-monaspice \
		nerd-fonts-monofur>0:x11-fonts/nerd-fonts-monofur \
		nerd-fonts-monoid>0:x11-fonts/nerd-fonts-monoid \
		nerd-fonts-mononoki>0:x11-fonts/nerd-fonts-mononoki \
		nerd-fonts-mplus>0:x11-fonts/nerd-fonts-mplus \
		nerd-fonts-noto>0:x11-fonts/nerd-fonts-noto \
		nerd-fonts-opendyslexic>0:x11-fonts/nerd-fonts-opendyslexic \
		nerd-fonts-overpass>0:x11-fonts/nerd-fonts-overpass \
		nerd-fonts-profont>0:x11-fonts/nerd-fonts-profont \
		nerd-fonts-proggyclean>0:x11-fonts/nerd-fonts-proggyclean \
		nerd-fonts-recmono>0:x11-fonts/nerd-fonts-recmono \
		nerd-fonts-robotomono>0:x11-fonts/nerd-fonts-robotomono \
		nerd-fonts-saucecodepro>0:x11-fonts/nerd-fonts-saucecodepro \
		nerd-fonts-shuretechmono>0:x11-fonts/nerd-fonts-shuretechmono \
		nerd-fonts-spacemono>0:x11-fonts/nerd-fonts-spacemono \
		nerd-fonts-symbols>0:x11-fonts/nerd-fonts-symbols \
		nerd-fonts-terminess>0:x11-fonts/nerd-fonts-terminess \
		nerd-fonts-tinos>0:x11-fonts/nerd-fonts-tinos \
		nerd-fonts-ubuntu>0:x11-fonts/nerd-fonts-ubuntu \
		nerd-fonts-ubuntumono>0:x11-fonts/nerd-fonts-ubuntumono \
		nerd-fonts-ubuntusans>0:x11-fonts/nerd-fonts-ubuntusans \
		nerd-fonts-victormono>0:x11-fonts/nerd-fonts-victormono \
		nerd-fonts-zedmono>0:x11-fonts/nerd-fonts-zedmono

USES=		metaport

.endif

.include <bsd.port.mk>
