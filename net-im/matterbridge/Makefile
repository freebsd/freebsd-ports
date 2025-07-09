PORTNAME=	matterbridge
PORTVERSION=	1.26.0
DISTVERSIONPREFIX=	v
PORTREVISION=	15
CATEGORIES=	net-im

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Chat network bridge
WWW=		https://github.com/42wim/matterbridge

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	42wim

USE_RC_SUBR=	matterbridge

MATTERBRIDGE_USER?=	mattermost
MATTERBRIDGE_GROUP?=	mattermost
USERS=		${MATTERBRIDGE_USER}
GROUPS=		${MATTERBRIDGE_GROUP}
SUB_LIST=	\
		MATTERBRIDGE_USER=${MATTERBRIDGE_USER} \
		MATTERBRIDGE_GROUP=${MATTERBRIDGE_GROUP}
PLIST_SUB=	\
		MATTERBRIDGE_USER=${MATTERBRIDGE_USER} \
		MATTERBRIDGE_GROUP=${MATTERBRIDGE_GROUP}

GH_TUPLE=	\
		42wim:go-gitter:017310c2d557:42wim_go_gitter/vendor/github.com/42wim/go-gitter \
		Baozisoftware:qrcode-terminal-go:c0650d8dff0f:baozisoftware_qrcode_terminal_go/vendor/github.com/Baozisoftware/qrcode-terminal-go \
		Benau:go_rlottie:98c1b2421989:benau_go_rlottie/vendor/github.com/Benau/go_rlottie \
		Benau:tgsconverter:99f4a4f6337f:benau_tgsconverter/vendor/github.com/Benau/tgsconverter \
		FiloSottile:edwards25519:v1.0.0:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
		Jeffail:gabs:v1.4.0:jeffail_gabs/vendor/github.com/Jeffail/gabs \
		Philipp15b:go-steam:6ae9b3c0a560:philipp15b_go_steam/vendor/github.com/Philipp15b/go-steam \
		Rhymen:go-whatsapp:31a2e740845c:rhymen_go_whatsapp/vendor/github.com/Rhymen/go-whatsapp \
		SevereCloud:vksdk:v2.15.0:severecloud_vksdk_v2/vendor/github.com/SevereCloud/vksdk/v2 \
		apex:log:v1.9.0:apex_log/vendor/github.com/apex/log \
		av-elier:go-decimal-to-rational:89e6aad02ecf:av_elier_go_decimal_to_rational/vendor/github.com/av-elier/go-decimal-to-rational \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		bwmarrin:discordgo:v0.27.0:bwmarrin_discordgo/vendor/github.com/bwmarrin/discordgo \
		d5:tengo:v2.13.0:d5_tengo_v2/vendor/github.com/d5/tengo/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		dyatlov:go-opengraph:dae8665a5b09:dyatlov_go_opengraph/vendor/github.com/dyatlov/go-opengraph \
		francoispqt:gojay:v1.2.13:francoispqt_gojay/vendor/github.com/francoispqt/gojay \
		fsnotify:fsnotify:v1.6.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gary-kim:go-nc-talk:v0.3.0:gary_kim_go_nc_talk/vendor/gomod.garykim.dev/nc-talk \
		go-asn1-ber:asn1-ber:v1.5.3:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-telegram-bot-api:telegram-bot-api:v5.5.1:go_telegram_bot_api_telegram_bot_api_v5/vendor/github.com/go-telegram-bot-api/telegram-bot-api/v5 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		golang-jwt:jwt:v3.2.2:golang_jwt_jwt/vendor/github.com/golang-jwt/jwt \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.4.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:image:v0.3.0:golang_image/vendor/golang.org/x/image \
		golang:mod:86c51ed26bb4:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.5.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.4.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.4.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.4.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.6.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.2.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.12:golang_tools/vendor/golang.org/x/tools \
		gomarkdown:markdown:663e2500819c:gomarkdown_markdown/vendor/github.com/gomarkdown/markdown \
		google:gops:v0.3.26:google_gops/vendor/github.com/google/gops \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		gopackage:ddp:v0.0.3:gopackage_ddp/vendor/github.com/gopackage/ddp \
		gorilla:schema:v1.2.0:gorilla_schema/vendor/github.com/gorilla/schema \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		graph-gophers:graphql-go:v1.3.0:graph_gophers_graphql_go/vendor/github.com/graph-gophers/graphql-go \
		harmony-development:shibshib:c98059d09cfa:harmony_development_shibshib/vendor/github.com/harmony-development/shibshib \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:golang-lru:v0.6.0:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		kettek:apng:414630eed80f:kettek_apng/vendor/github.com/kettek/apng \
		keybase:go-keybase-chat-bot:e48d9abd2c20:keybase_go_keybase_chat_bot/vendor/github.com/keybase/go-keybase-chat-bot \
		klauspost:compress:v1.15.8:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v2.0.12:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		kyokomi:emoji:v2.2.11:kyokomi_emoji_v2/vendor/github.com/kyokomi/emoji/v2 \
		labstack:echo:v4.10.0:labstack_echo_v4/vendor/github.com/labstack/echo/v4 \
		labstack:gommon:v0.4.0:labstack_gommon/vendor/github.com/labstack/gommon \
		layeh:gumble:d1df60a3cc14:layeh_gumble/vendor/layeh.com/gumble \
		lrstanley:girc:a92667a5c9b4:lrstanley_girc/vendor/github.com/lrstanley/girc \
		lukechampine:uint128:v1.2.0:lukechampine_uint128/vendor/lukechampine.com/uint128 \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		matterbridge:Rocket.Chat.Go.SDK:79310a412696:matterbridge_rocket_chat_go_sdk/vendor/github.com/matterbridge/Rocket.Chat.Go.SDK \
		matterbridge:go-xmpp:791a06c5f1be:matterbridge_go_xmpp/vendor/github.com/matterbridge/go-xmpp \
		matterbridge:gomatrix:271e5088ea27:matterbridge_gomatrix/vendor/github.com/matterbridge/gomatrix \
		matterbridge:gozulipbot:a19d6c1f3b75:matterbridge_gozulipbot/vendor/github.com/matterbridge/gozulipbot \
		matterbridge:logrus-prefixed-formatter:d971309a77ba:matterbridge_logrus_prefixed_formatter/vendor/github.com/matterbridge/logrus-prefixed-formatter \
		matterbridge:matterclient:272af20c7ddf:matterbridge_matterclient/vendor/github.com/matterbridge/matterclient \
		mattermost:go-i18n:5c415071e404:mattermost_go_i18n/vendor/github.com/mattermost/go-i18n \
		mattermost:ldap:ee0e6284187d:mattermost_ldap/vendor/github.com/mattermost/ldap \
		mattermost:logr:v1.0.13:mattermost_logr/vendor/github.com/mattermost/logr \
		mattermost:logr:v2.0.15:mattermost_logr_v2/vendor/github.com/mattermost/logr/v2 \
		mattermost:mattermost-server:v5.39.3:mattermost_mattermost_server_v5/vendor/github.com/mattermost/mattermost-server/v5 \
		mattermost:mattermost-server:v6.7.2:mattermost_mattermost_server_v6/vendor/github.com/mattermost/mattermost-server/v6 \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.16:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:godown:v0.0.1:mattn_godown/vendor/github.com/mattn/godown \
		mdp:qrterminal:v1.0.1:mdp_qrterminal/vendor/github.com/mdp/qrterminal \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		minio:md5-simd:v1.1.2:minio_md5_simd/vendor/github.com/minio/md5-simd \
		minio:minio-go:v7.0.24:minio_minio_go_v7/vendor/github.com/minio/minio-go/v7 \
		minio:sha256-simd:v1.0.0:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		monaco-io:request:v1.0.5:monaco_io_request/vendor/github.com/monaco-io/request \
		mreiferson:go-httpclient:5e475fde3a4d:mreiferson_go_httpclient/vendor/github.com/mreiferson/go-httpclient \
		mrexodia:wray:78a2c1f284ff:mrexodia_wray/vendor/github.com/mrexodia/wray \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		nelsonken:gomf:c65cc0469e94:nelsonken_gomf/vendor/github.com/nelsonken/gomf \
		olahol:melody:d52139073376:olahol_melody/vendor/gopkg.in/olahol/melody.v1 \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		paulrosania:go-charset:55c9d7a5834c:paulrosania_go_charset/vendor/github.com/paulrosania/go-charset \
		pborman:uuid:v1.2.1:pborman_uuid/vendor/github.com/pborman/uuid \
		pelletier:go-toml:v1.9.5:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pelletier:go-toml:v2.0.6:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		philhofer:fwd:v1.1.1:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.28.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		remyoudompheng:bigfft:eec4a21b6bb0:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		rickb777:date:v1.12.4:rickb777_date/vendor/github.com/rickb777/date \
		rickb777:plural:v1.2.0:rickb777_plural/vendor/github.com/rickb777/plural \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rs:xid:v1.4.0:rs_xid/vendor/github.com/rs/xid \
		rsc:qr:v0.2.0:rsc_qr/vendor/rsc.io/qr \
		saintfish:chardet:5e3ef4b5456d:saintfish_chardet/vendor/github.com/saintfish/chardet \
		shazow:rateio:4461efc8bdc4:shazow_rateio/vendor/github.com/shazow/rateio \
		shazow:ssh-chat:v1.10.1:shazow_ssh_chat/vendor/github.com/shazow/ssh-chat \
		sirupsen:logrus:v1.9.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sizeofint:webpanimation:1d2b32119882:sizeofint_webpanimation/vendor/github.com/sizeofint/webpanimation \
		skip2:go-qrcode:dc11ecdae0a9:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		slack-go:slack:v0.12.1:slack_go_slack/vendor/github.com/slack-go/slack \
		spf13:afero:v1.9.3:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.5.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.15.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.8.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.4.2:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tinylib:msgp:v1.1.6:tinylib_msgp/vendor/github.com/tinylib/msgp \
		tulir:libsignal-protocol-go:v0.1.0:tulir_libsignal_protocol_go/vendor/go.mau.fi/libsignal \
		tulir:whatsmeow:dcbc8dd31a22:tulir_whatsmeow/vendor/go.mau.fi/whatsmeow \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.8.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.21.0:uber_go_zap/vendor/go.uber.org/zap \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasttemplate:v1.2.2:valyala_fasttemplate/vendor/github.com/valyala/fasttemplate \
		vincent-petithory:dataurl:v1.0.0:vincent_petithory_dataurl/vendor/github.com/vincent-petithory/dataurl \
		vmihailenco:msgpack:v5.3.5:vmihailenco_msgpack_v5/vendor/github.com/vmihailenco/msgpack/v5 \
		vmihailenco:tagparser:v2.0.0:vmihailenco_tagparser_v2/vendor/github.com/vmihailenco/tagparser/v2 \
		wiggin77:cfg:v1.0.2:wiggin77_cfg/vendor/github.com/wiggin77/cfg \
		wiggin77:merror:v1.0.3:wiggin77_merror/vendor/github.com/wiggin77/merror \
		wiggin77:srslog:v1.0.1:wiggin77_srslog/vendor/github.com/wiggin77/srslog \
		writeas:go-strip-markdown:v2.0.1:writeas_go_strip_markdown/vendor/github.com/writeas/go-strip-markdown \
		yaegashi:msgraph.go:v0.1.4:yaegashi_msgraph_go/vendor/github.com/yaegashi/msgraph.go \
		zfjagann:golang-ring:19bcea1b6289:zfjagann_golang_ring/vendor/github.com/zfjagann/golang-ring

GL_TUPLE=	\
		cznic:cc:03159e8e41eec8d08c1e502bfc46868b9a03aa57:cznic_cc/vendor/modernc.org/cc/v3 \
		cznic:ccgo:0641811a3b4e1b829e42b48fa6cf751b3a681ed5:cznic_ccgo/vendor/modernc.org/ccgo/v3 \
		cznic:libc:bc4740f8667d1763148074e63f2e6f2e02a03daa:cznic_libc/vendor/modernc.org/libc \
		cznic:mathutil:b13e5b5643328f15fd2fcedc85f647f0d8f9180f:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:75976e411b2d8e904972fb8d6e26b6160202c8ac:cznic_memory/vendor/modernc.org/memory \
		cznic:opt:6b647abadf922391a4527f3a4fa1817eff08b7cd:cznic_opt/vendor/modernc.org/opt \
		cznic:sqlite:4dd882a3a5abf54993dd57e36bf96198fa22f89a:cznic_sqlite/vendor/modernc.org/sqlite \
		cznic:strutil:bba0c72b66bb9ced2dfd2ee521b7f16b2cbb39fa:cznic_strutil/vendor/modernc.org/strutil \
		cznic:token:a1b392cca155ddafa8e1e45905db0dfe27cd4714:cznic_token/vendor/modernc.org/token

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/russross
	@${RLN} ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/github.com/russross/blackfriday
#pre-patch:
#	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
#	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-install:
	${INSTALL_DATA} ${WRKSRC}/matterbridge.toml.sample ${STAGEDIR}${PREFIX}/etc/matterbridge.toml.sample

.include <bsd.port.mk>
