#!/bin/sh

WEBRTC_REV=7204c

base_url="https://chromium.googlesource.com/chromium/src/base.git/+archive/"
boringssl_url="https://boringssl.googlesource.com/boringssl.git/+archive/"
build_url="https://chromium.googlesource.com/chromium/src/build.git/+archive/"
buildtools_url="https://chromium.googlesource.com/chromium/src/buildtools.git/+archive/"
catapult_url="https://chromium.googlesource.com/catapult.git/+archive/"
icu_url="https://chromium.googlesource.com/chromium/deps/icu.git/+archive/"
libjpeg_turbo_url="https://chromium.googlesource.com/chromium/deps/libjpeg_turbo.git/+archive/"
libsrtp_url="https://chromium.googlesource.com/chromium/deps/libsrtp.git/+archive/"
libvpx_url="https://chromium.googlesource.com/webm/libvpx.git/+archive/"
libyuv_url="https://chromium.googlesource.com/libyuv/libyuv.git/+archive/"
nasm_url="https://chromium.googlesource.com/chromium/deps/nasm.git/+archive/"
perfetto_url="https://chromium.googlesource.com/external/github.com/google/perfetto.git/+archive/"
protobuf_javascript_url="https://chromium.googlesource.com/external/github.com/protocolbuffers/protobuf-javascript.git/+archive/"
re2_url="https://chromium.googlesource.com/external/github.com/google/re2.git/+archive/"
testing_url="https://chromium.googlesource.com/chromium/src/testing.git/+archive/"
third_party_url="https://chromium.googlesource.com/chromium/src/third_party.git/+archive/"
tools_url="https://chromium.googlesource.com/chromium/src/tools.git/+archive/"

fetch -q -o /tmp/DEPS https://raw.githubusercontent.com/signalapp/webrtc/${WEBRTC_REV}/DEPS

base_hash=$(grep 'base@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BASE_REV=\t${base_hash}\n"
printf "BASE_REV=\t${base_hash}\n" | portedit merge -i Makefile

boringssl_hash=$(grep 'boringssl.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BORINGSSL_REV=\t${boringssl_hash}\n"
printf "BORINGSSL_REV=\t${boringssl_hash}\n" | portedit merge -i Makefile

build_hash=$(grep 'build@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BUILD_REV=\t${build_hash}\n"
printf "BUILD_REV=\t${build_hash}\n" | portedit merge -i Makefile

buildtools_hash=$(grep 'buildtools@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BUILDTOOLS_REV=\t${buildtools_hash}\n"
printf "BUILDTOOLS_REV=\t${buildtools_hash}\n" | portedit merge -i Makefile

catapult_hash=$(grep 'catapult.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "CATAPULT_REV=\t${catapult_hash}\n"
printf "CATAPULT_REV=\t${catapult_hash}\n" | portedit merge -i Makefile

icu_hash=$(grep 'icu.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "ICU_REV=\t${icu_hash}\n"
printf "ICU_REV=\t${icu_hash}\n" | portedit merge -i Makefile

libjpeg_turbo_hash=$(grep 'libjpeg_turbo.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBJPEG_TURBO_REV=\t${libjpeg_turbo_hash}\n"
printf "LIBJPEG_TURBO_REV=\t${libjpeg_turbo_hash}\n" | portedit merge -i Makefile

libsrtp_hash=$(grep 'libsrtp.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBSRTP_REV=\t${libsrtp_hash}\n"
printf "LIBSRTP_REV=\t${libsrtp_hash}\n" | portedit merge -i Makefile

libvpx_hash=$(grep 'libvpx.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBVPX_REV=\t${libvpx_hash}\n"
printf "LIBVPX_REV=\t${libvpx_hash}\n" | portedit merge -i Makefile

libyuv_hash=$(grep 'libyuv.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBYUV_REV=\t${libyuv_hash}\n"
printf "LIBYUV_REV=\t${libyuv_hash}\n" | portedit merge -i Makefile

nasm_hash=$(grep 'nasm.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "NASM_REV=\t${nasm_hash}\n"
printf "NASM_REV=\t${nasm_hash}\n" | portedit merge -i Makefile

opus_hash=$(grep 'opus.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "OPUS_REV=\t${opus_hash}\n"
printf "OPUS_REV=\t${opus_hash}\n" | portedit merge -i Makefile

perfetto_hash=$(grep 'perfetto.git' /tmp/DEPS | awk -F '+' '{print $4}' | sed -e "s# ##g" -e "s#',##" -e "s#'##")
printf "PERFETTO_REV=\t${perfetto_hash}\n"
printf "PERFETTO_REV=\t${perfetto_hash}\n" | portedit merge -i Makefile

protobuf_javascript_hash=$(grep "protobuf-javascript' + '@'" /tmp/DEPS | awk -F '+' '{print $4}' | sed -e "s# ##g" -e "s#',##" -e "s#'##")
printf "PROTOBUFJS_REV=\t${protobuf_javascript_hash}\n"
printf "PROTOBUFJS_REV=\t${protobuf_javascript_hash}\n" | portedit merge -i Makefile

re2_hash=$(grep 're2.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "RE2_REV=\t${re2_hash}\n"
printf "RE2_REV=\t${re2_hash}\n" | portedit merge -i Makefile

testing_hash=$(grep 'testing@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "TESTING_REV=\t${testing_hash}\n"
printf "TESTING_REV=\t${testing_hash}\n" | portedit merge -i Makefile

third_party_hash=$(grep 'third_party@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "THIRD_PARTY_REV=\t${third_party_hash}\n"
printf "THIRD_PARTY_REV=\t${third_party_hash}\n" | portedit merge -i Makefile

tools_hash=$(grep 'src/tools@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "TOOLS_REV=\t${tools_hash}\n"
printf "TOOLS_REV=\t${tools_hash}\n" | portedit merge -i Makefile

mkdir -p dist_good

for c in base boringssl build buildtools catapult icu libjpeg_turbo libsrtp libvpx libyuv nasm perfetto protobuf_javascript re2 testing third_party tools
do
	hash=$(echo ${c}_hash)
	eval "hash=\$$hash"

	if [ ! -f /usr/ports/distfiles/${c}-${hash}.tar.gz ] && [ ! -f dist_good/${c}-${hash}.tar.gz ]; then
		url=$(echo ${c}_url)
		eval "url=\$$url"

		echo "Fetching ${url}${hash}.tar.gz"

		mkdir -p ${c}
		fetch -qo - ${url}${hash}.tar.gz | tar xf - -C ${c}
		tar czf dist_good/${c}-${hash}.tar.gz ${c}
		rm -rf ${c}
	fi
done

if [ ! -f /usr/ports/distfiles/opus-${opus_hash}.tar.gz ] && [ ! -f dist_good/opus-${opus_hash}.tar.gz ]; then
	echo "Fetching Opus"
	mkdir -p opus
	fetch -qo - https://codeload.github.com/xiph/opus/tar.gz/${opus_hash}?dummy=/ | tar xf - -C opus --strip-components 1
	tar czf dist_good/opus-${opus_hash}.tar.gz opus
	rm -rf dist_tmp/opus-${opus_hash}.tar.gz opus
fi

echo "Copy dist_good/* in /usr/ports/distfiles and run make makesum"
echo "rsync dist_good/ freefall:public_distfiles/ringrtc/"
