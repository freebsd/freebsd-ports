# Created by: Yonatan <onatan@gmail.com>

PORTNAME=	metasploit
DISTVERSION=	6.1.24
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	tanawts@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		nmap:security/nmap \
		rubygem-actionpack60>=6.0:www/rubygem-actionpack60 \
		rubygem-activerecord60>=6.0:databases/rubygem-activerecord60 \
		rubygem-activesupport60>=6.0:devel/rubygem-activesupport60 \
		rubygem-aws-sdk-ec2>=0:devel/rubygem-aws-sdk-ec2 \
		rubygem-aws-sdk-iam>=0:devel/rubygem-aws-sdk-iam \
		rubygem-aws-sdk-s3>=0:devel/rubygem-aws-sdk-s3 \
		rubygem-bcrypt>=0:security/rubygem-bcrypt \
		rubygem-bcrypt_pbkdf>=0:security/rubygem-bcrypt_pbkdf \
		rubygem-bson>=0:devel/rubygem-bson \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-concurrent-ruby>=0:devel/rubygem-concurrent-ruby \
		rubygem-dnsruby>=0:dns/rubygem-dnsruby \
		rubygem-ed25519>=0:security/rubygem-ed25519 \
		rubygem-em-http-request>=0:www/rubygem-em-http-request \
		rubygem-eventmachine>=0:devel/rubygem-eventmachine \
		rubygem-faker>=0:devel/rubygem-faker \
		rubygem-faye-websocket>=0:www/rubygem-faye-websocket \
		rubygem-filesize>=0:devel/rubygem-filesize \
		rubygem-hrr_rb_ssh-ed25519>=0:security/rubygem-hrr_rb_ssh-ed25519 \
		rubygem-http-cookie>=0:www/rubygem-http-cookie \
		rubygem-irb>=0:devel/rubygem-irb \
		rubygem-jsobfu>=0:www/rubygem-jsobfu \
		rubygem-json>=0:devel/rubygem-json \
		rubygem-metasm>=0:devel/rubygem-metasm \
		rubygem-metasploit-aggregator>=0:security/rubygem-metasploit-aggregator \
		rubygem-metasploit-concern>=0:security/rubygem-metasploit-concern \
		rubygem-metasploit-credential>=0:security/rubygem-metasploit-credential \
		rubygem-metasploit-model>=0:security/rubygem-metasploit-model \
		rubygem-metasploit-payloads>=2.0.54:security/rubygem-metasploit-payloads \
		rubygem-metasploit_data_models>=0:security/rubygem-metasploit_data_models \
		rubygem-metasploit_payloads-mettle>=1.0.10:security/rubygem-metasploit_payloads-mettle \
		rubygem-mqtt>=0:net/rubygem-mqtt \
		rubygem-msgpack>=0:devel/rubygem-msgpack \
		rubygem-nessus_rest>=0:security/rubygem-nessus_rest \
		rubygem-net-ldap>=0:net/rubygem-net-ldap \
		rubygem-net-ssh>=0:security/rubygem-net-ssh \
		rubygem-network_interface>=0:net/rubygem-network_interface \
		rubygem-nexpose>=0:security/rubygem-nexpose \
		rubygem-nokogiri>=0:textproc/rubygem-nokogiri \
		rubygem-octokit>=0:net/rubygem-octokit \
		rubygem-openssl-ccm>=0:security/rubygem-openssl-ccm \
		rubygem-openvas-omp>=0:security/rubygem-openvas-omp \
		rubygem-packetfu>=0:net/rubygem-packetfu \
		rubygem-patch_finder>=0:devel/rubygem-patch_finder \
		rubygem-pcaprub>=0:net/rubygem-pcaprub \
		rubygem-pdf-reader>=0:print/rubygem-pdf-reader \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-puma>=0:www/rubygem-puma \
		rubygem-railties60>=6.0:www/rubygem-railties60 \
		rubygem-recog>=0:security/rubygem-recog \
		rubygem-redcarpet>=0:textproc/rubygem-redcarpet \
		rubygem-reline>=0:devel/rubygem-reline \
		rubygem-rex-arch>=0:security/rubygem-rex-arch \
		rubygem-rex-bin_tools>=0:security/rubygem-rex-bin_tools \
		rubygem-rex-core>=0:security/rubygem-rex-core \
		rubygem-rex-encoder>=0:security/rubygem-rex-encoder \
		rubygem-rex-exploitation>=0:security/rubygem-rex-exploitation \
		rubygem-rex-java>=0:security/rubygem-rex-java \
		rubygem-rex-mime>=0:security/rubygem-rex-mime \
		rubygem-rex-nop>=0:security/rubygem-rex-nop \
		rubygem-rex-ole>=0:security/rubygem-rex-ole \
		rubygem-rex-powershell>=0:security/rubygem-rex-powershell \
		rubygem-rex-random_identifier>=0:security/rubygem-rex-random_identifier \
		rubygem-rex-registry>=0:security/rubygem-rex-registry \
		rubygem-rex-rop_builder>=0:security/rubygem-rex-rop_builder \
		rubygem-rex-socket>=0:security/rubygem-rex-socket \
		rubygem-rex-sslscan>=0:security/rubygem-rex-sslscan \
		rubygem-rex-struct2>=0:security/rubygem-rex-struct2 \
		rubygem-rex-text>=0:security/rubygem-rex-text \
		rubygem-rex-zip>=0:security/rubygem-rex-zip \
		rubygem-ruby-macho>=0:devel/rubygem-ruby-macho \
		rubygem-ruby_smb>=0:net/rubygem-ruby_smb \
		rubygem-rubyntlm>=0:net/rubygem-rubyntlm \
		rubygem-rubyzip>=0:archivers/rubygem-rubyzip \
		rubygem-sinatra>=0:www/rubygem-sinatra \
		rubygem-sqlite3>=0:databases/rubygem-sqlite3 \
		rubygem-sshkey>=0:security/rubygem-sshkey \
		rubygem-swagger-blocks>=0:devel/rubygem-swagger-blocks \
		rubygem-thin>=0:www/rubygem-thin \
		rubygem-tzinfo-data>=0:devel/rubygem-tzinfo-data \
		rubygem-tzinfo>=0:devel/rubygem-tzinfo \
		rubygem-unix-crypt>=0:security/rubygem-unix-crypt \
		rubygem-warden>=0:devel/rubygem-warden \
		rubygem-windows_error>=0:devel/rubygem-windows_error \
		rubygem-winrm>=0:sysutils/rubygem-winrm \
		rubygem-xdr>=0:converters/rubygem-xdr \
		rubygem-xmlrpc>=0:net/rubygem-xmlrpc \
		rubygem-zeitwerk>=0:devel/rubygem-zeitwerk

USES=		cpe go:run python shebangfix
CPE_VENDOR=	rapid7
USE_GITHUB=	yes
GH_ACCOUNT=	rapid7
GH_PROJECT=	metasploit-framework
USE_RUBY=	yes

SHEBANG_FILES=	data/exploits/CVE-2017-17562/build.sh \
		data/exploits/CVE-2017-17562/install-deps.sh \
		data/exploits/CVE-2017-7494/build.sh \
		data/exploits/CVE-2017-7494/install-deps.sh \
		data/exploits/CVE-2021-3156/nss_generic2.py \
		data/exploits/CVE-2021-3156/nss_u14.py \
		data/exploits/CVE-2021-3156/nss_u16.py \
		data/exploits/CVE-2021-3156/userspec_c7.py \
		data/exploits/CVE-2021-3156/userspec_generic.py \
		docker/bin/msfconsole docker/bin/msfvenom docker/entrypoint.sh \
		external/source/exploits/CVE-2020-9850/payload/loader/make.py \
		external/source/exploits/CVE-2020-9850/payload/sbx/build-threadexec.sh \
		external/source/exploits/CVE-2020-9850/payload/sbx/build-webkit.sh \
		external/source/exploits/CVE-2020-9850/payload/sbx/embed.py \
		external/source/metsvc/test.rb \
		external/source/msfJavaToolkit/compile.sh \
		external/source/msfJavaToolkit/testCompilation.rb \
		external/source/msfJavaToolkit/testKeytool.rb \
		external/source/shellcode/windows/build.sh \
		external/source/shellcode/windows/x64/build.py \
		external/source/shellcode/windows/x86/build.py \
		external/source/shellcode/windows/x86/src/hash.py \
		modules/auxiliary/admin/http/cisco_7937g_ssh_privesc.py \
		modules/auxiliary/admin/http/grafana_auth_bypass.py \
		modules/auxiliary/admin/teradata/teradata_odbc_sql.py \
		modules/auxiliary/dos/cisco/cisco_7937g_dos.py \
		modules/auxiliary/dos/cisco/cisco_7937g_dos_reboot.py \
		modules/auxiliary/dos/http/slowloris.py \
		modules/auxiliary/dos/tcp/claymore_dos.py \
		modules/auxiliary/example.py \
		modules/auxiliary/gather/get_user_spns.py \
		modules/auxiliary/gather/mikrotik_winbox_fileread.py \
		modules/auxiliary/gather/office365userenum.py \
		modules/auxiliary/scanner/http/onion_omega2_login.py \
		modules/auxiliary/scanner/http/rdp_web_login.py \
		modules/auxiliary/scanner/msmail/exchange_enum.go \
		modules/auxiliary/scanner/msmail/host_id.go \
		modules/auxiliary/scanner/msmail/onprem_enum.go \
		modules/auxiliary/scanner/smb/impacket/dcomexec.py \
		modules/auxiliary/scanner/smb/impacket/secretsdump.py \
		modules/auxiliary/scanner/smb/impacket/wmiexec.py \
		modules/auxiliary/scanner/ssl/bleichenbacher_oracle.py \
		modules/auxiliary/scanner/teradata/teradata_odbc_login.py \
		modules/auxiliary/scanner/wproxy/att_open_proxy.py \
		modules/exploits/example.py \
		modules/exploits/linux/smtp/haraka.py \
		tools/dev/import-dev-keys.sh tools/dev/sign-dev-keys.sh \
		tools/dev/update_joomla_components.py \
		tools/hardware/killerbee_msfrelay.py \
		tools/modules/aws-aggregator-userdata.sh
SHEBANG_LANG=	go

STRIP=
NO_ARCH=	yes
NO_ARCH_IGNORE=	template_x64_bsd.bin template_x86_bsd.bin CVE-2013-2171.bin

post-patch:
	${REINPLACE_CMD} 's,git ls-files,find . ! -type d | sed "s|^./||", ; \
		/rb-readline/d' \
		${WRKSRC}/metasploit-framework.gemspec
	${REINPLACE_CMD} "/concurrent-ruby/s|,'1.0.5'|| ; /reline/s|, '0.2.5'|| ; /pcaprub/s|, '0.12.4'||" \
		${WRKSRC}/metasploit-framework.gemspec

do-build:
	${RM} ${WRKSRC}/Gemfile.lock
	${TOUCH} ${WRKSRC}/Gemfile.lock
	${REINPLACE_CMD} "/^group :coverage/,/^end/d ; /^group :development/,/^end/d ; /^group :test/,/^end/d ; /git:/d ; /sqlite3/s|, '~>1.3.0'||" \
		${WRKSRC}/Gemfile

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${PAX} -rw . ${STAGEDIR}${DATADIR}
.for f in msfconsole msfd msfdb msfrpc msfrpcd msfvenom
	${RLN} ${STAGEDIR}${DATADIR}/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install:
	@${FIND} ${STAGEDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; /Gemfile.lock/s|^|@(,,0666) |' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DATADIR} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
