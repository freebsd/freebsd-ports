begin
network 127.0.0.0/24
# ADD YOUR NETWORKS HERE
log squirm/logs/match.log
abort-log squirm/logs/abort.log
pattern zap.patterns get
end
