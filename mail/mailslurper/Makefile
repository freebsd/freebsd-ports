PORTNAME=	mailslurper
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.15.0
PORTREVISION=	1
CATEGORIES=	mail

MAINTAINER=	einar@isnic.is
COMMENT=	Local, web-based mail server application. Slurp mails into oblivion!
WWW=		https://github.com/mailslurper/mailslurper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes

GH_TUPLE=	\
		adampresley:webframework:0c93acb6716f:adampresley_webframework/vendor/github.com/adampresley/webframework \
		denisenkom:go-mssqldb:bbfc9a55622e:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		golang-sql:civil:cb61b32ac6fe:golang_sql_civil/vendor/github.com/golang-sql/civil \
		golang:crypto:2aa609cf4a9d:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:0de0cce0169b:golang_net/vendor/golang.org/x/net \
		golang:sys:04cbcbbfeed8:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.2.0:gorilla_sessions/vendor/github.com/gorilla/sessions \
		jinzhu:copier:b57f9002281a:jinzhu_copier/vendor/github.com/jinzhu/copier \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		labstack:echo-contrib:v0.8.0:labstack_echo_contrib/vendor/github.com/labstack/echo-contrib \
		labstack:echo:v4.1.14:labstack_echo_v4/vendor/github.com/labstack/echo/v4 \
		labstack:gommon:v0.3.0:labstack_gommon/vendor/github.com/labstack/gommon \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v2.0.3:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		microcosm-cc:bluemonday:v1.0.2:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		skratchdot:open-golang:eef842397966:skratchdot_open_golang/vendor/github.com/skratchdot/open-golang \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasttemplate:v1.1.0:valyala_fasttemplate/vendor/github.com/valyala/fasttemplate

GO_TARGET=	./cmd/${GH_PROJECT}

PLIST_FILES=	bin/mailslurper

.include <bsd.port.mk>
