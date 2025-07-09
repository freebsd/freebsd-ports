PORTNAME=	beehive
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	29
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Flexible event/agent & automation system with lots of bees
WWW=		https://github.com/muesli/beehive

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go-bindata:devel/go-bindata

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	muesli
GH_TUPLE=	ChimeraCoder:anaconda:v2.0.0:chimeracoder_anaconda/vendor/github.com/ChimeraCoder/anaconda \
		ChimeraCoder:tokenbucket:c5a927568de7:chimeracoder_tokenbucket/vendor/github.com/ChimeraCoder/tokenbucket \
		CleverbotIO:go-cleverbot.io:d24926702e8d:cleverbotio_go_cleverbot_io/vendor/github.com/CleverbotIO/go-cleverbot.io \
		MariaTerzieva:gotumblr:93ca5e50a3fd:mariaterzieva_gotumblr/vendor/github.com/MariaTerzieva/gotumblr \
		Profpatsch:GoOse:da5de31b9bd2:profpatsch_goose/vendor/github.com/Profpatsch/GoOse \
		PuerkitoBio:goquery:v1.5.0:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		akashshinde:go_cricket:01a06b2c3f22:akashshinde_go_cricket/vendor/github.com/akashshinde/go_cricket \
		alexcesaro:quotedprintable:2caba252f4dc:alexcesaro_quotedprintable/vendor/gopkg.in/alexcesaro/quotedprintable.v3 \
		andybalholm:cascadia:v1.0.0:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		araddon:dateparse:0d74ffceef83:araddon_dateparse/vendor/github.com/araddon/dateparse \
		asaskevich:EventBus:d46933a94f05:asaskevich_eventbus/vendor/github.com/asaskevich/EventBus \
		azr:backoff:53511d3c7330:azr_backoff/vendor/github.com/azr/backoff \
		beorn7:perks:3a771d992973:beorn7_perks/vendor/github.com/beorn7/perks \
		briandowns:openweathermap:5f41b7c9d92d:briandowns_openweathermap/vendor/github.com/briandowns/openweathermap \
		bwmarrin:discordgo:v0.19.0:bwmarrin_discordgo/vendor/github.com/bwmarrin/discordgo \
		carlosdp:twiliogo:b26045ebb9d1:carlosdp_twiliogo/vendor/github.com/carlosdp/twiliogo \
		cloudflare:cloudflare-go:v0.10.6:cloudflare_cloudflare_go/vendor/github.com/cloudflare/cloudflare-go \
		coreos:go-systemd:fd7a80b32e1f:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deckarep:gosx-notifier:e127226297fb:deckarep_gosx_notifier/vendor/github.com/deckarep/gosx-notifier \
		dustin:go-jsonpointer:ba0abeacc3dc:dustin_go_jsonpointer/vendor/github.com/dustin/go-jsonpointer \
		dustin:gojson:2e71ec9dd5ad:dustin_gojson/vendor/github.com/dustin/gojson \
		emicklei:go-restful:v2.9.3:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		fatih:set:v0.2.1:fatih_set/vendor/github.com/fatih/set \
		flashmob:go-guerrilla:07043ae76e81:flashmob_go_guerrilla/vendor/github.com/flashmob/go-guerrilla \
		fluffle:goirc:v1.0.1:fluffle_goirc/vendor/github.com/fluffle/goirc \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		garyburd:go-oauth:bca2e7f09a17:garyburd_go_oauth/vendor/github.com/garyburd/go-oauth \
		gempir:go-twitch-irc:v2.2.2:gempir_go_twitch_irc_v2/vendor/github.com/gempir/go-twitch-irc/v2 \
		gigawattio:window:0f5467e35573:gigawattio_window/vendor/github.com/gigawattio/window \
		glaxx:go_pastebin:7e72d56770d0:glaxx_go_pastebin/vendor/github.com/glaxx/go_pastebin \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/github.com/go-ini/ini \
		go-mail:mail:v2.3.1:go_mail_mail/vendor/github.com/go-mail/mail \
		go-telegram-bot-api:telegram-bot-api:v4.6.4:go_telegram_bot_api_telegram_bot_api/vendor/github.com/go-telegram-bot-api/telegram-bot-api \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.5.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:a29dc8fdc734:golang_crypto/vendor/golang.org/x/crypto \
		golang:freetype:e2365dfdc4a0:golang_freetype/vendor/github.com/golang/freetype \
		golang:image:6d32002ffd75:golang_image/vendor/golang.org/x/image \
		golang:mock:v1.2.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:da9a3fd4c582:golang_net/vendor/golang.org/x/net \
		golang:oauth2:9f3314589c9a:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:c4c64cad1fd0:golang_time/vendor/golang.org/x/time \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		guelfey:go.dbus:f6a3a2366cc3:guelfey_go_dbus/vendor/github.com/guelfey/go.dbus \
		horrendus:go-mixcloud:c2164c9e194c:horrendus_go_mixcloud/vendor/github.com/horrendus/go-mixcloud \
		huandu:facebook:v2.3.1:huandu_facebook/vendor/github.com/huandu/facebook \
		jacobsa:go-serial:15cf729a72d4:jacobsa_go_serial/vendor/github.com/jacobsa/go-serial \
		jayeshsolanki93:devgorant:69fb03e5c3b1:jayeshsolanki93_devgorant/vendor/github.com/jayeshsolanki93/devgorant \
		jaytaylor:html2text:01ec452cbe43:jaytaylor_html2text/vendor/github.com/jaytaylor/html2text \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		json-iterator:go:v1.1.6:json_iterator_go/vendor/github.com/json-iterator/go \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		kurrik:oauth1a:cb1b80e32dd4:kurrik_oauth1a/vendor/github.com/kurrik/oauth1a \
		layeh:gumble:1ea1159c4956:layeh_gumble/vendor/layeh.com/gumble \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-colorable:v0.1.1:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.7:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-mastodon:v0.0.3:mattn_go_mastodon/vendor/github.com/mattn/go-mastodon \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-xmpp:6093f50721ed:mattn_go_xmpp/vendor/github.com/mattn/go-xmpp \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		minio:minio-go:v6.0.14:minio_minio_go/vendor/github.com/minio/minio-go \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mreiferson:go-httpclient:31f0106b4474:mreiferson_go_httpclient/vendor/github.com/mreiferson/go-httpclient \
		mrexodia:wray:78a2c1f284ff:mrexodia_wray/vendor/github.com/mrexodia/wray \
		muesli:beehive-admin-dist:648f36d:muesli_beehive_admin_dist/vendor/github.com/muesli/beehive-admin-dist \
		muesli:clusters:ba9c57dd9228:muesli_clusters/vendor/github.com/muesli/clusters \
		muesli:gamut:0d3f7d26a44e:muesli_gamut/vendor/github.com/muesli/gamut \
		muesli:go-pkg-rss:3bef0f3126ec:muesli_go_pkg_rss/vendor/github.com/muesli/go-pkg-rss \
		muesli:go-pkg-xmlx:76f54ee73233:muesli_go_pkg_xmlx/vendor/github.com/muesli/go-pkg-xmlx \
		muesli:go.hue:8aefcc693caf:muesli_go_hue/vendor/github.com/muesli/go.hue \
		muesli:goefa:08d8ee2555d2:muesli_goefa/vendor/github.com/muesli/goefa \
		muesli:kmeans:80dfc71e6c5a:muesli_kmeans/vendor/github.com/muesli/kmeans \
		muesli:smolder:9c21fc7135ee:muesli_smolder/vendor/github.com/muesli/smolder \
		nicklaw5:helix:v0.5.7:nicklaw5_helix/vendor/github.com/nicklaw5/helix \
		nlopes:slack:v0.6.0:nlopes_slack/vendor/github.com/nlopes/slack \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		odwrtw:transmission:08885b3058e7:odwrtw_transmission/vendor/github.com/odwrtw/transmission \
		olekukonko:tablewriter:v0.0.1:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v0.9.2:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:5c3871d89910:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:4724e9255275:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:1dc9a6cbc91a:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rdegges:go-ipify:2d94a6a86c40:rdegges_go_ipify/vendor/github.com/rdegges/go-ipify \
		rogpeppe:go-charset:2471d30d28b4:rogpeppe_go_charset/vendor/github.com/rogpeppe/go-charset \
		shuheiktgw:go-travis:2d0b3e9898f0:shuheiktgw_go_travis/vendor/github.com/shuheiktgw/go-travis \
		simplepush:simplepush-go:8980e96b7b02:simplepush_simplepush_go/vendor/github.com/simplepush/simplepush-go \
		sirupsen:logrus:v1.4.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sromku:go-gitter:70f7030a94a6:sromku_go_gitter/vendor/github.com/sromku/go-gitter \
		ssor:bom:6386211fdfcf:ssor_bom/vendor/github.com/ssor/bom \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		technoweenie:multipartstreamer:v1.0.1:technoweenie_multipartstreamer/vendor/github.com/technoweenie/multipartstreamer \
		tomnomnom:linkheader:02ca5825eb80:tomnomnom_linkheader/vendor/github.com/tomnomnom/linkheader \
		wcharczuk:go-chart:v2.0.1:wcharczuk_go_chart/vendor/github.com/wcharczuk/go-chart \
		xrash:smetrics:a3153f7040e9:xrash_smetrics/vendor/github.com/xrash/smetrics

USE_RC_SUBR=	${PORTNAME}

_BUILD_TAGS=	-tags "embed"
_BUILD_SHA=	7447df7

GO_BUILDFLAGS=	${_BUILD_TAGS} \
		-ldflags "\
		${STRIP} -w \
		-X main.Version=${DISTVERSION} \
		-X main.CommitSHA=${_BUILD_SHA}"

SUB_LIST=	GROUPS="${GROUPS}" \
		USERS="${USERS}"

_BEEHIVE_USER=	${PORTNAME}
USERS=		${_BEEHIVE_USER}
GROUPS=		${_BEEHIVE_USER}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} -r ${WRKSRC}/config
	@${RLN} ${WRKSRC_muesli_beehive_admin_dist} ${WRKSRC}/config

pre-build:
	(cd ${WRKSRC} && \
		${LOCALBASE}/bin/go-bindata ${_BUILD_TAGS} --pkg api -o api/bindata.go --ignore config/.git assets/... config/...)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
