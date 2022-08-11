PORTNAME=	mate-themes
PORTVERSION=	3.22.23
CATEGORIES=	x11-themes mate
MASTER_SITES=	MATE/themes/${PORTVERSION:R}/
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of themes and icons for MATE

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	gtk-engines2>=2.15.0:x11-themes/gtk-engines2 \
		gtk-murrine-engine>=0.98:x11-themes/gtk-murrine-engine

PORTSCOUT=	limit:^${PORTVERSION:R:S|.|\.|}\.*$$

USES=		gettext gmake gnome localbase pathfix pkgconfig tar:xz
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes

LOCALES=	af am an ar ar_SA as ast az be bg bn bn_IN br \
		bs ca ca@valencia cmn crh cs csb cv cy da de \
		de_AT de_CH dk dz ee el en en_AU en_CA en_DE \
		en_GB eo es es_419 es_AR es_CL es_CO es_CR es_DO \
		es_EC es_ES es_MX es_NI es_PA es_PE es_PR es_SV \
		es_US es_UY es_VE et eu fa fa_IR fi fil fo fr \
		fr_CA fr_FR frp fur fy ga gd gl gu gug_PY ha he \
		hi hr hu hy ia id ie ig is it ja jv ka kab kk \
		km kn ko ks ku ku_IQ ky la lb li lo lt lv mai \
		mg mi mk ml mn mr ms mt my nah nb nds ne nl nn \
		no nqo nso oc om or pa pl pl_PL pms ps pt pt_BR \
		pt_PT ro ru ru_RU rw sc sco si sk sl so sq sr \
		sr@Latn sr@latin sv sw ta te tg th tk tl tr ts \
		tt ug uk uk_UA ur ur_PK uz uz@Latn vi wa xh yi \
		yo zh zh-Hans zh_CN zh_CN.GB2312 zh_HK zh_TW \
		zh_TW.Big5 zu

post-install:
.for l in ${LOCALES}
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/${l}/LC_MESSAGES
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/${l}
.endfor

.include <bsd.port.mk>
